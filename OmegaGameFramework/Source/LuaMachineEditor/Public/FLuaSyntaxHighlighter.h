#pragma once

#include "CoreMinimal.h"
#include "Framework/Text/SyntaxHighlighterTextLayoutMarshaller.h"
#include "Framework/Text/SyntaxTokenizer.h"
#include "Framework/Text/IRun.h"
#include "Framework/Text/TextLayout.h"

class FLuaSyntaxHighlighter : public FSyntaxHighlighterTextLayoutMarshaller
{
public:
    static TSharedRef<FLuaSyntaxHighlighter> Create();

    virtual void ParseTokens(const FString& SourceString, FTextLayout& TargetTextLayout, TArray<FSyntaxTokenizer::FTokenizedLine> TokenizedLines) override;

protected:
    FLuaSyntaxHighlighter(TSharedPtr<FSyntaxTokenizer> InTokenizer);

private:
    FTextBlockStyle NormalTextStyle;
    FTextBlockStyle KeywordTextStyle;
    FTextBlockStyle StringTextStyle;
    FTextBlockStyle CommentTextStyle;
    FTextBlockStyle NumberTextStyle;
    
    TSet<FString> LuaKeywords;
    
    static TSharedRef<FSyntaxTokenizer> CreateTokenizer();
};