#define U_CHARSET_IS_UTF8 1

#include "unicode/utf8.h"
#include "unicode/utypes.h"
#include "unicode/uchar.h"

#include "RunArray.h"

#ifdef __cplusplus

#include "unicode/regex.h"
#include "unicode/uregex.h"
#include "unicode/uniset.h"
#include "unicode/ustring.h"

extern "C" {
#endif
    
    struct ICUString {
#ifdef __cplusplus
        icu::UnicodeString* instance;
#else
        void*               instance;
#endif
        
        const UChar*        (*getBuffer)(struct ICUString self);
        int32_t             (*getLength)(struct ICUString self);
        void                (*append)(struct ICUString self, const UChar* str, int32_t length);
        void                (*appendUnicodeString)(struct ICUString self, struct ICUString other);
        void                (*replace)(struct ICUString self, int32_t start, int32_t length, const UChar* str, int32_t strLength);
        struct ICUString    (*substring)(struct ICUString self, int32_t start, int32_t length);
        int                 (*compare)(struct ICUString self, const UChar *otherChars, int32_t otherLength);
        void                (*replacingOccurrences)(struct ICUString self, struct ICUString oldChars, struct ICUString newChars);
        void                (*remove)(struct ICUString self, int32_t start, int32_t length);
        UChar*              (*getMutableBuffer)(struct ICUString self, int32_t capacity);
        void                (*releaseMutableBuffer)(struct ICUString self, int32_t newLength);
        struct ICUString    (*clone)(struct ICUString self);
        int32_t             (*indexOf)(struct ICUString self, struct ICUString other, int32_t start, int32_t length);

    };
    typedef struct ICUString ICUString;
    
    ICUString newICUString();
    ICUString newICUStringWithCapacity(int32_t capacity);
    ICUString newICUStringWithBytes(const UChar* str, int32_t length);
    ICUString newICUStringFromUTF8(const unsigned char* str, int32_t length);
    ICUString newICUStringSubstring(ICUString self, int32_t start, int32_t length);
    void deleteICUString(ICUString self);

    
#ifdef __cplusplus
}

extern "C" {
#endif
    
    struct ICUSet {
#ifdef __cplusplus
        icu::UnicodeSet*    instance;
#else
        void*               instance;
#endif
        UBool               (*contains)(struct ICUSet self, UChar character);
        int32_t             (*span)(struct ICUSet self, const UChar *uchars, int32_t length);
        int32_t             (*spanBack)(struct ICUSet self, const UChar *uchars, int32_t length);
        int32_t             (*spanReverse)(struct ICUSet self, const UChar* uchars, int32_t length);
        void                (*addAll)(struct ICUSet self, struct ICUSet other);
        struct ICUSet       (*inverted)(struct ICUSet self);
        
    };
    typedef struct ICUSet ICUSet;
    
    ICUSet newICUSet(const UChar* characters, int32_t length);
    // TODO: make va_args
    ICUSet unionForICUSets(ICUSet set, ICUSet other);
    void deleteICUSet(ICUSet self);
    
#ifdef __cplusplus
}

extern "C" {
#endif
    
    struct ICURegexMatcher {
#ifdef __cplusplus
        icu::RegexMatcher*  instance;
#else
        void*               instance;
#endif
        void                (*region)(struct ICURegexMatcher self, int32_t start, int32_t limit, UErrorCode *status);
        UBool               (*find)(struct ICURegexMatcher self, UErrorCode *status);
        int32_t             (*start)(struct ICURegexMatcher self, UErrorCode *status);
        int32_t             (*end)(struct ICURegexMatcher self, UErrorCode *status);
        int32_t             (*groupCount)(struct ICURegexMatcher self);
        int32_t             (*startForGroup)(struct ICURegexMatcher self, int32_t group, UErrorCode *status);
        int32_t             (*endForGroup)(struct ICURegexMatcher self, int32_t group, UErrorCode *status);
        ICUString           (*replaceAll)(struct ICURegexMatcher self, ICUString str, UErrorCode *status);
        int32_t*            (*getTextCheckingResult)(struct ICURegexMatcher self, int32_t *length, UErrorCode *status);
        
    };
    typedef struct ICURegexMatcher ICURegexMatcher;
    
    void deleteICURegexMatcher(ICURegexMatcher self);
    
#ifdef __cplusplus
}

extern "C" {
#endif
    
    struct ICURegexPattern {
#ifdef __cplusplus
        icu::RegexPattern*  instance;
#else
        void*               instance;
#endif
        ICURegexMatcher      (*matcher)(struct ICURegexPattern self, ICUString str, UErrorCode *status);
        
    };
    typedef struct ICURegexPattern ICURegexPattern;
    
    ICURegexPattern compilePattern(ICUString str, int32_t flags, UErrorCode *status);
    void deleteICURegexPattern(ICURegexPattern self);
    
#ifdef __cplusplus
}
#endif


















