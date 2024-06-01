import sys

def remove_lines_until_hash(lines):
    for line in lines:
        if line.startswith("#"):
            yield line
            break

if __name__ == "__main__":
    lines = sys.stdin.readlines()
    filtered_lines = remove_lines_until_hash(lines)
    for line in filtered_lines:
        sys.stdout.write(line)