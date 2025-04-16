import pathlib
import subprocess

# Thats where our cpps are currently
BASE_PATH = "files/"

def find_all_cpp_files(findWorking):
    vorkurs_path = pathlib.Path(BASE_PATH)
    broken_cpp_files = set(vorkurs_path.rglob("*broken.cpp"))

    if not findWorking:
        return [str(cpp_file) for cpp_file in broken_cpp_files]

    cpp_files = set(vorkurs_path.rglob("*.cpp"))
    working_cpp_files = cpp_files.difference(broken_cpp_files)
    return [str(cpp_file) for cpp_file in working_cpp_files]


def test_single_cpp_file(file_path, shouldCompile):
    compile_status = subprocess.getoutput(f"g++ {file_path} -w")

    if compile_status != "" and shouldCompile:
        print("\n" + 20 * "=")
        print(f"Error in file {file_path}:\n")
        print(compile_status)
        print(20 * "=" + "\n")

        return False
    elif compile_status == "" and not shouldCompile:
        print("\n" + 20 * "=")
        print(f"File {file_path} compiles, but should be broken")
        print("\n" + 20 * "=")

        return False

    return True

def main():
    error_count_working = 0
    error_count_broken = 0
    working_cpp_files = find_all_cpp_files(True)
    broken_cpp_files = find_all_cpp_files(False)

    for cpp_file in working_cpp_files:
        if not test_single_cpp_file(cpp_file, True):
            error_count_working += 1

    for cpp_file in broken_cpp_files:
        if not test_single_cpp_file(cpp_file, False):
            error_count_broken += 1

    if error_count_working > 0:
        print(
            f"::error::Found {error_count_working} non compiling files which should compile"
        )
       
    if error_count_broken > 0:
        print(
            f"::error::Found {error_count_broken} files that should be broken but compile"
        )

    if error_count_broken > 0 or error_count_working > 0:
        exit(1)

    exit(0)


if __name__ == "__main__":
    main()
