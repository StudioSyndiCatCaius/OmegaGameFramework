// Copyright Incanta Games 2021. All Rights Reserved.

#pragma once

#include <ios>

UENUM( BlueprintType )
enum class EFileSDKFileAnchor : uint8 {
  /**
   * References the beginning of the file. Great for reading metadata, resetting your location,
   * or just going to exact location. If you're in the middle of the file and want to to go to
   * 300 bytes from the beginning, set Anchor to Beginning and Offset to 300. A negative Offset
   * doesn't make sense when using Beginning.
   */
  Beginning,

  /**
   * References the current location of the file reader. Great for skipping chunks of data
   * (i.e. your file has an array of stuff and you only want to read the metadata headers for
   * each item, you can read the metadata, skip past the actual chunk, and go to the next
   * metadata location) If you want to advanced your current location 100 bytes backwards,
   * set Anchor to Current and Offset to -100.
   */
  Current,

  /**
   * References the end of the file. Great for reading footers where information is stored
   * at the end of the file. Many times you use this when you open the file, but the metadata
   * you want is near the end of the file a fixed number of bytes. For example, 300 bytes from
   * the end would have Anchor set to End and Offset set to -300. A positive Offset doesn't
   * make sense when using Beginning.
   */
  End
};
