import os
import fileinput

def is_text_file(file_path):
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            f.read()
        return True
    except (UnicodeDecodeError, IsADirectoryError, PermissionError):
        return False

def replace_text_in_files_and_rename(folder_name, search_text, replace_text):
    folder_path = os.path.abspath(folder_name)

    edited_files = []  # To store the names of edited files

    for root, _, files in os.walk(folder_path):
        for file in files:
            file_path = os.path.join(root, file)

            if os.path.isfile(file_path) and is_text_file(file_path):
                # Replace text within the file
                with fileinput.FileInput(file_path, inplace=True) as f:
                    for line in f:
                        edited_line = line.replace(search_text, replace_text)
                        print(edited_line, end='')
                        if edited_line != line:
                            edited_files.append(file_path)

                # Rename the file if the filename contains the search_text
                new_file_name = file.replace(search_text, replace_text)
                if new_file_name != file:
                    new_file_path = os.path.join(root, new_file_name)
                    os.rename(file_path, new_file_path)

    if edited_files:
        print("\nEdited files:")
        for edited_file in edited_files:
            print(edited_file)
    
    input("Press Enter to close...")

if __name__ == "__main__":
    folder_name = input("Enter the folder name: ")
    search_text = input("Enter the text to search for: ")
    replace_text = input("Enter the text to replace with: ")

    replace_text_in_files_and_rename(folder_name, search_text, replace_text)
