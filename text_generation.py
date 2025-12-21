import random

# List of sample phrases to randomize

phrases = [
    "The telescope revealed distant galaxies spinning in the void.",
    "Open-source software thrives on community collaboration.",
    "A quiet forest provides the perfect backdrop for reflection.",
    "Neural networks mimic the structure of the human brain.",
    "Time is the most valuable asset a person can spend.",
    "The city skyline glittered under a blanket of fog.",
    "Optimization is the process of making a system fully functional.",
    "Every sunset brings the promise of a new dawn."
]

# Create the file and write 3000 lines
text = input("wish file: ")

with open(text, "w") as f:
    for i in range(1, 3001):
        line_content = random.choice(phrases)
        f.write(f"Line {i}: {line_content}\n")

print(f"Success! '{text}' with 3,000 lines has been generated.")
