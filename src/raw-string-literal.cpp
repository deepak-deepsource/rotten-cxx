// scatr-check: CXX-W2025

// [CXX-W2025]
char const *const BackSlash("goink\\frob");
char const *const PlainLiteral("plain literal");

// Non-printable ASCII characters.
char const *const Nul("goink\\\000");
char const *const Soh("goink\\\001");
char const *const Stx("goink\\\002");
char const *const Etx("goink\\\003");
char const *const Enq("goink\\\004");
char const *const Ack("goink\\\005");
char const *const Bell("goink\\\afrob");
char const *const BackSpace("goink\\\bfrob");
char const *const HorizontalTab("goink\\\tfrob");
char const *const NewLine("goink\nfrob");
char const *const VerticalTab("goink\\\vfrob");
char const *const FormFeed("goink\\\ffrob");
char const *const CarraigeReturn("goink\\\rfrob");
char const *const So("goink\\\016");
char const *const Si("goink\\\017");
char const *const Dle("goink\\\020");
char const *const Dc1("goink\\\021");
char const *const Dc2("goink\\\022");
char const *const Dc3("goink\\\023");
char const *const Dc4("goink\\\024");
char const *const Nak("goink\\\025");
char const *const Syn("goink\\\026");
char const *const Etb("goink\\\027");
char const *const Can("goink\\\030");
char const *const Em("goink\\\031");
char const *const Sub("goink\\\032");
char const *const Esc("goink\\\033");
char const *const Fs("goink\\\034");
char const *const Gs("goink\\\035");
char const *const Rs("goink\\\036");
char const *const Us("goink\\\037");
char const *const HexNonPrintable("\\\x03");
char const *const Delete("\\\177");
char const *const MultibyteSnowman("\xE2\x98\x83");
char const *const TrailingSpace("A line \\with space. \n");
char const *const TrailingNewLine("A single \\line.\n");
char const *const AlreadyRaw(R"(foobie\\bletch)");
auto const *const UTF8Literal(u8"foobie\\bletch");
auto const *const UTF8RawLiteral(u8R"(foobie\\bletch)");
// TODO: enable these tests once all supported compilers
// support char16_t and char32_t (VS2013 does not)
// char16_t const *const UTF16Literal(u"foobie\\bletch");
// char16_t const *const UTF16RawLiteral(uR"(foobie\\bletch)");
// char32_t const *const UTF32Literal(U"foobie\\bletch");
// char32_t const *const UTF32RawLiteral(UR"(foobie\\bletch)");
wchar_t const *const WideLiteral(L"foobie\\bletch");
wchar_t const *const WideRawLiteral(LR"(foobie\\bletch)");
// [CXX-W2025]
char const *const SingleQuote("goink\'frob");
// [CXX-W2025]
char const *const DoubleQuote("goink\"frob");
// [CXX-W2025]
char const *const QuestionMark("goink\?frob");
// [CXX-W2025]
char const *const RegEx("goink\\(one|two\\)\\\\\\?.*\\nfrob");
// [CXX-W2025]
char const *const Path("C:\\Program Files\\Vendor\\Application\\Application.exe");
// [CXX-W2025]
char const *const ContainsSentinel("who\\ops)\"");
// [CXX-W2025]
char const *const ContainsDelim("whoops)\")lit\"");

// Don't replace these, because the raw literal would be longer.
char const *const JustAQuote("quote:\'");
char const *const NeedDelimiter("\":)\"");

char const *const OctalPrintable("\100\\");
char const *const HexPrintable("\x40\\");
char const *const prettyFunction(__PRETTY_FUNCTION__);
char const *const function(__FUNCTION__);
char const *const func(__func__);

#define TRICK(arg_) #arg_
char const *const MacroBody = TRICK(foo\\bar);

#define HAT(rabbit_) #rabbit_ "foo\\bar"
char const *const StringizedMacroArgument = HAT(foo\\bar);

#define SUBST(lit_) lit_
char const *const MacroArgument = SUBST("foo\\bar");
// FIXME: We should be able to replace this string literal macro argument

template <typename T>
void fn(char const *const Arg) {
char const *const Str("foo\\bar");
}

template <>
void fn<int>(char const *const Arg) {
char const *const Str("foo\\bar");
}

void callFn() {
fn<int>("foo\\bar");
    fn<double>("foo\\bar");
}

// [CXX-W2025]
char const *const ManyQuotes("quotes:\'\'\'\'");
// [CXX-W2025]
char const *const LongOctal("\042\072\051\042");
