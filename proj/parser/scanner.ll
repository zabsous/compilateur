%{

#include "scanner.hh"
#include <cstdlib>

#define YY_NO_UNISTD_H

using token = yy::Parser::token;

#undef  YY_DECL
#define YY_DECL int Scanner::yylex( yy::Parser::semantic_type * const lval, yy::Parser::location_type *loc )

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option c++
%option yyclass="Scanner"
%option noyywrap

debutComment    \%\%\%
milieuComment   (([\%]{1,2}[^\%])|([^\%]*))*
finComment      \%\%\%

%%
%{
    yylval = lval;
%}

"+" return '+';
"*" return '*';
"-" return '-';
"=" return '=';
"/" return '/';
"(" return '(';
")" return ')';
"{" return '{';
"}" return '}';
"!" return '!';
"[" return '[';
"]" return ']';
":" return ':';
"," return ',';
"%" return '%';

{debutComment}{milieuComment}{finComment} {
    std::cout << "commentaire multi ligne : " << YYText() << std::endl;
    yylval->build<std::string>(YYText());
    return token::COMMENTAIRE;
}

(?i:pour) {
    return token::POUR;
}

"["[0-9]+","[0-9]+"]" {
    yylval->build<std::string>(YYText());
    return token::RANGE;
}

(?i:fini) {
    return token::FINI;
}

(?i:si) {
    return token::SI;
}

(?i:alors) {
    return token::ALORS;
}

(?i:sinon) {
    return token::SINON;
}

(?i:finsi) {
    return token::FINSI;
}

"==" {
    return token::EGAL;
}

"!=" {
    return token::DIFFERENT;
}

"<=" {
    return token::LESSEROREQUAL;
}

">=" {
    return token::GREATEROREQUAL;
}

"<" {
    return token::LESSER;
}

">" {
    return token::GREATER;
}

(?i:rgb) {
    return token::COULEUR;
}

#[0-9A-Fa-f]{6} {
    yylval->build<std::string>(YYText());
    return token::COULEURHEXA;
}

\%\%[^\n]* {
    std::cout << "commentaire 1 ligne : " << YYText() << std::endl;
    yylval->build<std::string>(YYText());
    return token::COMMENTAIRE;
}

![T]{1,9} {
    yylval->build<int>(yyleng-1); // yyleng donne la taille du texte
    return token::TITLE;
}
![T]{1,9}"["[0-9]*"]" {
    yylval->build<std::string>(YYText());
    return token::TITLEID;
}
titre[0-9] {
    yylval->build<std::string>(YYText());
    return token::UNIVTITLE;
}
!I {
    return token::IMAGE;
}
!I\[[0-9]*\] {
    yylval->build<std::string>(YYText());
    return token::IMAGEID;
}
!P {
    return token::PARAGRAPH;
}
!P\[[0-9]*\] {
    yylval->build<std::string>(YYText());
    return token::PARAGRAPHID;
}
paragraphe {
    return token::UNIVPARAGRAPH;
}
page {
    return token::UNIVPAGE;
}

@DEFINE {
    return token::DEFINE;
}
@TITREPAGE {
    return token::TITREPAGE;
}
encodage {
    std::cout << "encodage" << std::endl;
    return token::ENCODAGE;
}
icone {
    return token::ICONE;
}
css {
    return token::CSS;
}
langue {
    return token::LANGUE;
}

largeur {
    return token::LARGEUR;
}
hauteur {
    return token::HAUTEUR;
}
couleurTexte {
    return token::COULEURTEXTE;
}
couleurFond {
    return token::COULEURFOND;
}
opacite {
    return token::OPACITE;
}

px {
    return token::PIXEL;
}

@STYLE {
    return token::STYLE;
}

'([^']|\\\')*' {
    yylval->build<std::string>(YYText());
    return token::TEXT;
}

[0-9]+      {
    yylval->build<int>(std::atoi(YYText()));
    return token::NUMBER;
}

[ \t\r]+ {
}

"\n"+         {
    loc->lines();
    return token::NL;
}


[a-zA-Z][0-9a-zA-Z]* {
    yylval->build<std::string>(YYText());
    return token::VAR;
}

[a-zA-Z][0-9a-zA-Z]*.(largeur|hauteur|couleurTexte|couleurFond|opacite|style) {
    yylval->build<std::string>(YYText()); //l'on a choisi de ne pas mettre un accent a opacite
    return token::VARATTRIBUT;
}

style {
    return token::STYLESELEC;
}

<<EOF>> {
    return token::END;
}

%%

