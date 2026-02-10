#include "FLuaSyntaxHighlighter.h"
#include "Framework/Text/SlateTextRun.h"

TSharedRef<FSyntaxTokenizer> FLuaSyntaxHighlighter::CreateTokenizer()
{
    TArray<FSyntaxTokenizer::FRule> TokenizerRules;

    // Comments (put comments BEFORE strings so they take priority)
    TokenizerRules.Add(FSyntaxTokenizer::FRule(TEXT("--\\[\\[[^\\]]*\\]\\]"))); // Multi-line comments
    TokenizerRules.Add(FSyntaxTokenizer::FRule(TEXT("--[^\\n]*"))); // Single line comments
    
    // Strings (single and double quotes, and multi-line strings)
    TokenizerRules.Add(FSyntaxTokenizer::FRule(TEXT("\"[^\"]*\""))); // Double quoted strings
    TokenizerRules.Add(FSyntaxTokenizer::FRule(TEXT("'[^']*'"))); // Single quoted strings
    TokenizerRules.Add(FSyntaxTokenizer::FRule(TEXT("\\[\\[[^\\]]*\\]\\]"))); // Multi-line strings
    
    // Numbers
    TokenizerRules.Add(FSyntaxTokenizer::FRule(TEXT("\\b\\d+\\.?\\d*\\b")));
    TokenizerRules.Add(FSyntaxTokenizer::FRule(TEXT("0x[0-9a-fA-F]+"))); // Hex numbers

    return FSyntaxTokenizer::Create(TokenizerRules);
}

TSharedRef<FLuaSyntaxHighlighter> FLuaSyntaxHighlighter::Create()
{
    TSharedPtr<FSyntaxTokenizer> Tokenizer = CreateTokenizer();
    return MakeShareable(new FLuaSyntaxHighlighter(Tokenizer));
}

FLuaSyntaxHighlighter::FLuaSyntaxHighlighter(TSharedPtr<FSyntaxTokenizer> InTokenizer)
    : FSyntaxHighlighterTextLayoutMarshaller(InTokenizer)
{
    // Define text styles
    NormalTextStyle = FTextBlockStyle()
        .SetFont(FCoreStyle::GetDefaultFontStyle("Mono", 9))
        .SetColorAndOpacity(FLinearColor(0.9f, 0.9f, 0.9f, 1.0f));

    KeywordTextStyle = FTextBlockStyle()
        .SetFont(FCoreStyle::GetDefaultFontStyle("Mono", 9))
        .SetColorAndOpacity(FLinearColor(1.0f, 0.2f, 0.2f, 1.0f)); // Red

    StringTextStyle = FTextBlockStyle()
        .SetFont(FCoreStyle::GetDefaultFontStyle("Mono", 9))
        .SetColorAndOpacity(FLinearColor(0.9f, 0.6f, 0.4f, 1.0f)); // Orange

    CommentTextStyle = FTextBlockStyle()
        .SetFont(FCoreStyle::GetDefaultFontStyle("Mono", 9))
        .SetColorAndOpacity(FLinearColor(0.3f, 0.35f, 0.3f, 1.0f)); // Green

    NumberTextStyle = FTextBlockStyle()
        .SetFont(FCoreStyle::GetDefaultFontStyle("Mono", 9))
        .SetColorAndOpacity(FLinearColor(0.2f, 1.0f, 0.4f, 1.0f)); // Light green

    // Lua keywords
    LuaKeywords = {
        TEXT("and"), TEXT("break"), TEXT("do"), TEXT("else"), TEXT("elseif"),
        TEXT("end"), TEXT("false"), TEXT("for"), TEXT("function"), TEXT("if"),
        TEXT("in"), TEXT("local"), TEXT("nil"), TEXT("not"), TEXT("or"),
        TEXT("repeat"), TEXT("return"), TEXT("then"), TEXT("true"), TEXT("until"),
        TEXT("while"), TEXT("goto")
    };
}

void FLuaSyntaxHighlighter::ParseTokens(const FString& SourceString, FTextLayout& TargetTextLayout, TArray<FSyntaxTokenizer::FTokenizedLine> TokenizedLines)
{
    TArray<FTextLayout::FNewLineData> LinesToAdd;
    LinesToAdd.Reserve(TokenizedLines.Num());

    for (const FSyntaxTokenizer::FTokenizedLine& TokenizedLine : TokenizedLines)
    {
        TSharedRef<FString> ModelString = MakeShareable(new FString());
        TArray<TSharedRef<IRun>> Runs;

        for (const FSyntaxTokenizer::FToken& Token : TokenizedLine.Tokens)
        {
            const FString TokenText = SourceString.Mid(Token.Range.BeginIndex, Token.Range.Len());
            
            FTextRange ModelRange(ModelString->Len(), ModelString->Len() + TokenText.Len());
            ModelString->Append(TokenText);

            FRunInfo RunInfo(TEXT("SyntaxHighlight.Lua.Normal"));
            FTextBlockStyle TextBlockStyle = NormalTextStyle;

            // Determine token type and apply appropriate style
            bool bIsSpecialToken = false;
            
            if (Token.Type == FSyntaxTokenizer::ETokenType::Syntax)
            {
                // Check for comments first (they start with --)
                if (TokenText.StartsWith(TEXT("--")))
                {
                    RunInfo.Name = TEXT("SyntaxHighlight.Lua.Comment");
                    TextBlockStyle = CommentTextStyle;
                    bIsSpecialToken = true;
                }
                // Check for strings (anything starting with quotes or [[)
                else if (TokenText.StartsWith(TEXT("\"")) || TokenText.StartsWith(TEXT("'")) || 
                         (TokenText.StartsWith(TEXT("[[")) && TokenText.EndsWith(TEXT("]]"))))
                {
                    RunInfo.Name = TEXT("SyntaxHighlight.Lua.String");
                    TextBlockStyle = StringTextStyle;
                    bIsSpecialToken = true;
                }
                // Check for numbers
                else if (TokenText.IsNumeric() || TokenText.StartsWith(TEXT("0x")) || 
                         (TokenText.Len() > 0 && FChar::IsDigit(TokenText[0])))
                {
                    RunInfo.Name = TEXT("SyntaxHighlight.Lua.Number");
                    TextBlockStyle = NumberTextStyle;
                    bIsSpecialToken = true;
                }
            }
            
            if (!bIsSpecialToken && Token.Type == FSyntaxTokenizer::ETokenType::Literal)
            {
                // Check if it's a keyword
                if (LuaKeywords.Contains(TokenText))
                {
                    RunInfo.Name = TEXT("SyntaxHighlight.Lua.Keyword");
                    TextBlockStyle = KeywordTextStyle;
                }
                // Check if it's a number (for literals that look numeric)
                else if (TokenText.IsNumeric())
                {
                    RunInfo.Name = TEXT("SyntaxHighlight.Lua.Number");
                    TextBlockStyle = NumberTextStyle;
                }
            }

            TSharedRef<ISlateRun> Run = FSlateTextRun::Create(RunInfo, ModelString, TextBlockStyle, ModelRange);
            Runs.Add(Run);
        }

        LinesToAdd.Emplace(MoveTemp(ModelString), MoveTemp(Runs));
    }

    TargetTextLayout.AddLines(LinesToAdd);
}