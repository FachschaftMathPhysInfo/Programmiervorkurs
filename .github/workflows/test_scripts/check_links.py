import re
import subprocess
import ssl
import socket
from urllib.parse import urlparse

def extract_urls(file_path):
    with open(file_path, 'r', encoding='latin-1') as file:
        content = file.read()
    url_pattern = re.compile(r'https?:\/\/(www\.)?[-a-zA-Z0-9@:%._\+~#=]{1,256}\.[a-zA-Z0-9()]{1,6}\b([-a-zA-Z0-9()@:%_\+.~#?&//=]*)')
    urls = url_pattern.findall(content)
    return sorted(set(url[0] for url in urls))

def check_url(url):
    if not url.startswith("https://"):
        print(f"ERROR: URL is not HTTPS: {url}")
        return False

    try:
        subprocess.run(["curl", "-Isf", "--fail-early", "--connect-timeout", "10", url], check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except subprocess.CalledProcessError as e:
        curl_error = e.stderr.decode() if e.stderr else ""
        if "Failed to connect" in curl_error:
            print(f"ERROR: Connection failed: {url}")
        elif "Could not resolve host" in curl_error:
            print(f"ERROR: DNS resolution failed: {url}")
        elif "SSL certificate problem" in curl_error:
            print(f"ERROR: Initial SSL certificate problem: {url}")
        else:
            print(f"ERROR: Failed to access: {url} (curl error: {curl_error})")

        hostname = urlparse(url).hostname
        try:
            with socket.create_connection((hostname, 443), timeout=10) as sock:
                context = ssl.create_default_context()
                with context.wrap_socket(sock, server_hostname=hostname) as ssock:
                    ssock.do_handshake()
        except ssl.SSLError:
            print("  -> CERTIFICATE ERROR DETECTED!")
        return False
    return True

def main():
    file_path = "vorkurs.pdf"
    urls = extract_urls(file_path)
    error_count = 0

    for url in urls:
        print(f"Checking URL: {url}")
        if not check_url(url):
            error_count += 1

    if error_count > 0:
        print(f"::error::Found {error_count} broken or insecure links!")
        exit(1)

if __name__ == "__main__":
    main()

