import pathlib
import subprocess

BASE_PATH = "vorkurs/"

def find_all_cpp_files():
    #vorkurs_path = pathlib.Path(BASE_PATH)
    vorkurs_path = pathlib.Path("/home/jan/Coding/Ende/Programmiervorkurs/vorkurs")
    cpp_files = set(vorkurs_path.rglob("*.cpp"))
    broken_cpp_files = set(vorkurs_path.rglob("*broken.cpp"))
    working_cpp_files = cpp_files.difference(broken_cpp_files)

    return [str(cpp_file) for cpp_file in working_cpp_files]

def test_single_cpp_file(file_path):
    compile_status = subprocess.getoutput(f"g++ {file_path}")

    if compile_status != "":
        print("\n"+20*"=")
        print(f"Error in file {file_path}:\n")
        print(compile_status)
        print(20*"="+"\n")

def main():
    working_cpp_files = find_all_cpp_files()

    for cpp_file in working_cpp_files:
        test_single_cpp_file(cpp_file)

if __name__ == "__main__":
    main()
