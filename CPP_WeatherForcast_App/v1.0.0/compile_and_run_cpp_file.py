import subprocess
import os
def compile_and_run_cpp(file_name):
    # Ensure the file has a .cpp extension
    temp_file_name = file_name + ".cpp"

    # Compile the C++ file
    compile_command = ["g++", temp_file_name, "-o", file_name]
    print("Compiling:", " ".join(compile_command))
    result = subprocess.run(compile_command, capture_output=True, text=True)
    
    # Check if compilation was successful
    if result.returncode != 0:
        print("Compilation failed!")
        print("Compiler Output:\n", result.stderr)
        return
    
    print("Compilation successful!")

    os.system(f"./{file_name}")






if __name__ == "__main__":
    file_name = input("Enter the C++ file name (without .cpp extension): ")
    compile_and_run_cpp(file_name)
