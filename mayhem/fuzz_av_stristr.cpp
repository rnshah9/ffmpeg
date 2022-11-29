#include <stdint.h>
#include <stdio.h>
#include <climits>

#include <fuzzer/FuzzedDataProvider.h>

extern "C" char *av_stristr(const char *haystack, const char *needle);

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);

    std::string str = provider.ConsumeRandomLengthString(1000);
    std::string str2 = provider.ConsumeRandomLengthString(1000);
    const char* haystack = str.c_str();
    const char* needle = str2.c_str();

    av_stristr(haystack, needle);

    return 0;
}