
#import <Foundation/Foundation.h>

// A generic class for arbitrary base-2 to 128 string encoding and decoding.
@interface GTMStringEncoding : NSObject {
@private
    NSData *charMapData_;
    char *charMap_;
    int reverseCharMap_[128];
    int shift_;
    int mask_;
    BOOL doPad_;
    char paddingChar_;
    int padLen_;
}

// Create a new, autoreleased GTMStringEncoding object with a standard encoding.

+ (id)base64WebsafeStringEncoding;

// Create a new, autoreleased GTMStringEncoding object with the given string,
// as described below.
+ (id)stringEncodingWithString:(NSString *)string;

// Initialize a new GTMStringEncoding object with the string.
//
// The length of the string must be a power of 2, at least 2 and at most 128.
// Only 7-bit ASCII characters are permitted in the string.
//
// These characters are the canonical set emitted during encoding.
// If the characters have alternatives (e.g. case, easily transposed) then use
// addDecodeSynonyms: to configure them.
- (id)initWithString:(NSString *)string;

// Add decoding synonyms as specified in the synonyms argument.
//
// It should be a sequence of one previously reverse mapped character,
// followed by one or more non-reverse mapped character synonyms.
// Only 7-bit ASCII characters are permitted in the string.
//
// e.g. If a GTMStringEncoder object has already been initialised with a set
// of characters excluding I, L and O (to avoid confusion with digits) and you
// want to accept them as digits you can call addDecodeSynonyms:@"0oO1iIlL".
- (void)addDecodeSynonyms:(NSString *)synonyms;

// A sequence of characters to ignore if they occur during encoding.
// Only 7-bit ASCII characters are permitted in the string.
- (void)ignoreCharacters:(NSString *)chars;

// Indicates whether padding is performed during encoding.
- (BOOL)doPad;
- (void)setDoPad:(BOOL)doPad;

// Sets the padding character to use during encoding.
- (void)setPaddingChar:(char)c;

// Encode a raw binary buffer to a 7-bit ASCII string.
- (NSString *)encode:(NSData *)data;
- (NSString *)encodeString:(NSString *)string;

// Decode a 7-bit ASCII string to a raw binary buffer.
- (NSData *)decode:(NSString *)string;
- (NSString *)stringByDecoding:(NSString *)string;

@end
