#!/usr/bin/env python3
"""Generate a 256x256 black texture with white wrapped text."""

import os
import sys
import textwrap

try:
    from PIL import Image, ImageDraw, ImageFont
except ImportError as e:
    print(f"Error: {e}")
    print("Please install Pillow: pip install Pillow")
    input("Press Enter to close...")
    sys.exit(1)


def create_text_texture(text: str, output_path: str):
    """Create a 256x256 black image with centered white text that wraps."""
    size = 256
    img = Image.new("RGB", (size, size), color="black")
    draw = ImageDraw.Draw(img)

    # Try to use a nice font, fall back to default
    font_size = 20
    try:
        font = ImageFont.truetype("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", font_size)
    except OSError:
        try:
            # Windows fallback
            font = ImageFont.truetype("arial.ttf", font_size)
        except OSError:
            font = ImageFont.load_default()

    # Calculate how many characters fit per line (approximate)
    avg_char_width = font_size * 0.6
    max_chars_per_line = int((size - 20) / avg_char_width)  # 10px padding each side

    # Wrap the text
    wrapped_lines = textwrap.wrap(text, width=max_chars_per_line)

    # Calculate total text height
    line_height = font_size + 4
    total_height = len(wrapped_lines) * line_height

    # Starting Y position to center vertically
    y = (size - total_height) // 2

    # Draw each line centered horizontally
    for line in wrapped_lines:
        bbox = draw.textbbox((0, 0), line, font=font)
        text_width = bbox[2] - bbox[0]
        x = (size - text_width) // 2
        draw.text((x, y), line, fill="white", font=font)
        y += line_height

    img.save(output_path)
    print(f"Saved texture to {output_path}")
    return img


if __name__ == "__main__":
    try:
        # Get the directory where this script is located
        script_dir = os.path.dirname(os.path.abspath(__file__))
        output_file = os.path.join(script_dir, "texture.png")

        user_text = input("Enter text for the texture: ")
        create_text_texture(user_text, output_file)
        print("Done!")
    except Exception as e:
        print(f"Error: {e}")
    
    input("Press Enter to close...")