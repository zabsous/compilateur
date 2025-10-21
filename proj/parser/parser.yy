%skeleton "lalr1.cc"
%require "3.0"

%defines
%define api.parser.class { Parser }
%define api.value.type variant
%define parse.assert

%locations

%code requires{
    #include "../expressions/affectation.hh"
    #include "../expressions/contexte.hh"
    #include "../expressions/expressionBinaire.hh"
    #include "../expressions/expressionUnaire.hh"
    #include "../expressions/constante.hh"
    #include "../expressions/variable.hh"
    #include "../expressions/define.hh"
    #include "../expressions/instruction.hh"
    #include "../expressions/bloc.hh"
    #include "../expressions/programme.hh"
    #include "../expressions/commentaire.hh"
    #include "../expressions/selecteur.hh"
    #include "../expressions/selecteurModifier.hh"
    #include "../expressions/styleBloc.hh"
    #include "../expressions/variable.hh"

    class Scanner;
    class Driver;
}

%parse-param { Scanner &scanner }
%parse-param { Driver &driver }
%parse-param { Programme &programme }

%code{
    #include <iostream>
    #include <string>
    #include <algorithm>
    
    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex
}

%token                  NL
%token                  END
%token <int>            NUMBER
%token <std::string>    HEXANUMBER
%token <std::string>    VAR
%token <std::string>    VARATTRIBUT
%token                  COULEUR
%token <std::string>    COULEURHEXA
%token <int>            TITLE
%token <std::string>    TITLEID
%token <std::string>    TEXT
%token                  IMAGE
%token <std::string>    IMAGEID
%token                  PARAGRAPH
%token <std::string>    PARAGRAPHID
%token                  UNIVPAGE
%token <std::string>    UNIVTITLE
%token                  UNIVPARAGRAPH
%token <std::string>    COMMENTAIRE
%token                  STYLESELEC

%token                  DEFINE
%token                  TITREPAGE

%token                  ENCODAGE
%token                  ICONE
%token                  CSS
%token                  LANGUE

%token                  LARGEUR
%token                  HAUTEUR
%token                  COULEURTEXTE
%token                  COULEURFOND
%token                  OPACITE

%token                  PIXEL

%token                  STYLE

%token                  SI
%token                  ALORS
%token                  SINON
%token                  FINSI
%token                  EGAL
%token                  DIFFERENT
%token                  GREATER
%token                  LESSER
%token                  GREATEROREQUAL
%token                  LESSEROREQUAL

%token                  POUR
%token <std::string>    RANGE
%token                  FINI

%type <int>             operation
%type <std::shared_ptr<Bloc>> bloc
%type <std::shared_ptr<Style>> attributs
%type <std::shared_ptr<Attribut>> attribut
%type <std::shared_ptr<Couleur>> couleur 
%type <std::string> blocuniv

%type <int>             number
%type <std::string>     textebloc
%left '-' '+'
%left '*' '/'
%precedence  NEG

%%

programme:
    instruction NL programme
    | instruction programme
    | NL END {
        YYACCEPT;
    }
    | END {
        YYACCEPT;
    }

si:
    SI comparaison ':' instruction SINON ':' instruction FINSI
    | SI comparaison ':' instruction SINON ':' instruction FINSI NL
    | SI comparaison ':' instruction FINSI NL
    | SI comparaison ':' instruction FINSI

pourinterne :
    instruction NL pourinterne
    | instruction pourinterne
    | instruction
    | NL

pour :
    POUR VAR RANGE '+' number ':' pourinterne FINI{
    }
    | POUR VAR RANGE '-' number ':' NL pourinterne FINI{
    }
    | POUR VAR RANGE '+' number ':' NL pourinterne FINI{
    }
    | POUR VAR RANGE '-' number ':' pourinterne FINI{
    }

instruction:
    pour {}
    | si {}
    | expression  {
        YYACCEPT;
    }
    | affectation {
    }
    | bloc '[' attributs ']' textebloc{
        std::cout<<$5<<std::endl;
        $1->setInnerTexte($5);
        $1->setStyle($3);
        programme.ajouter($1);
    }
    | bloc textebloc{
        $1->setInnerTexte($2);
        programme.ajouter($1);
    }
    | style {}
    
    | parametre {}

    | COMMENTAIRE {
        programme.ajouter(std::make_shared<Commentaire>($1));
    }

textebloc :
    TEXT textebloc {
        $$ = $1 + $2;
    }
    | operation textebloc {
        std::cout<<std::to_string($1);
        $$ = std::to_string($1) + $2;
    }
    | VAR textebloc {
        //a completer
    }
    | TEXT {
        $$ = $1;
    }
    | operation {
        std::cout<<std::to_string($1);
        $$ = std::to_string($1);
    }
    | VAR {
        //a completer
    }

style:
    STYLE '(' blocuniv ')' '[' attributs ']' {
        programme.ajouter(std::make_shared<StyleBloc>($3, $6));
    }
    | STYLE '(' blocuniv ')' '[' NL attributs ']' {
        programme.ajouter(std::make_shared<StyleBloc>($3, $7));
    }
    
nomattribut :
    LARGEUR
    | HAUTEUR
    | OPACITE
    | COULEURTEXTE
    | COULEURFOND

attribut:
    LARGEUR ':' number {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::largeur, $3);
        $$ = attribut;
    }
    | LARGEUR ':' number PIXEL { // on pourrait factoriser px mais la compléxité rajouté me semble peut nécessaire pour l'utilisation faite
        auto attribut = std::make_shared<AttributEntier>(TAttributs::largeur, $3, "px");
        $$ = attribut;
    }
    | HAUTEUR ':' number {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::hauteur, $3);
        $$ = attribut;
    }
    | HAUTEUR ':' number PIXEL {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::hauteur, $3, "px");
        $$ = attribut;
    }
    | OPACITE ':' number {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::opacite, $3);
        $$ = attribut;
    }
    | OPACITE ':' number '%' {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::opacite, $3, "%");
        $$ = attribut;
    }
    | COULEURTEXTE ':' couleur {
        auto attribut = std::make_shared<AttributCouleur>(TAttributs::couleurTexte, $3);
        $$ = attribut;
    }
    | COULEURFOND ':' couleur {
        auto attribut = std::make_shared<AttributCouleur>(TAttributs::couleurFond, $3);
        $$ = attribut;
    }
    | LARGEUR ':' VAR {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::largeur, 1);
        $$ = attribut;
    }
    | LARGEUR ':' VAR PIXEL { // on pourrait factoriser px mais la compléxité rajouté me semble peut nécessaire pour l'utilisation faite
        auto attribut = std::make_shared<AttributEntier>(TAttributs::largeur, 1, "px");
        $$ = attribut;
    }
    | HAUTEUR ':' VAR {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::hauteur, 1);
        $$ = attribut;
    }
    | HAUTEUR ':' VAR PIXEL {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::hauteur, 1, "px");
        $$ = attribut;
    }
    | OPACITE ':' VAR {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::opacite, 1);
        $$ = attribut;
    }
    | OPACITE ':' VAR '%' {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::opacite, 1, "%");
        $$ = attribut;
    }
    | COULEURTEXTE ':' VAR {
        auto coultest = std::make_shared<Couleur>("0","0","0",true);
        auto attribut = std::make_shared<AttributCouleur>(TAttributs::couleurTexte, coultest);
        $$ = attribut;
    }
    | COULEURFOND ':' VAR {
        auto coultest = std::make_shared<Couleur>("0","0","0",true);
        auto attribut = std::make_shared<AttributCouleur>(TAttributs::couleurFond, coultest);
        $$ = attribut;
    }
    

couleur:
    COULEUR '(' number ',' number ',' number ')' {
        if($3>=0 && $3<=255 && $5>=0 && $5<=255 && $7>=0 && $7<=255) { // pourrait être traité dans l'ast
            $$ = std::make_shared<Couleur>(std::to_string($3), std::to_string($5), std::to_string($7), false);
            
            std::cout <<  "couleur(" << $3 << "," << $5 << "," << $7 << ")";
        }
        else
        {
            std::cout <<  "erreur";
        }
    }
    | COULEURHEXA {
        std::string r = $1.substr(1,2);
        std::string g = $1.substr(3,2); 
        std::string b = $1.substr(5,2);

        $$ = std::make_shared<Couleur>(r, g, b, true);

        std::cout << "couleur(" << std::stoi($1.substr(1,2),0,16) << "," << std::stoi($1.substr(3,2),0,16)  << "," << std::stoi($1.substr(5,2),0,16)  << ")"; 
    }

attributs:
    attribut ',' attributs {
        auto style = $3;
        style->ajouterAttr($1);
        $$ = style;
    }
    | attribut NL attributs {
        auto style = $3;
        style->ajouterAttr($1);
        $$ = style;
    }
    | attribut NL {
        auto style = std::make_shared<Style>();
        style->ajouterAttr($1);
        $$ = style;
    }
    | attribut {
        auto style = std::make_shared<Style>();
        style->ajouterAttr($1);
        $$ = style;
    }
    
number :
    NUMBER {
        $$ = $1;
    }
    | VAR {
        std::cout<< "variable de nombre :";
    }
    | VARATTRIBUT {
        std::cout << "attribut de variable de nombre :" <<$1;
    }


parametre:
    TITREPAGE TEXT {
        programme.ajouter(std::make_shared<Define>(nomPropriete::titre, $2));
    }
    | DEFINE '(' ENCODAGE ')' '{' TEXT '}'  {
        programme.ajouter(std::make_shared<Define>(nomPropriete::encodage, $6));
    }
    | DEFINE '(' ICONE ')' '{' TEXT '}'  {
        programme.ajouter(std::make_shared<Define>(nomPropriete::icone, $6));
    }
    | DEFINE '(' CSS ')' '{' TEXT '}'  {
        programme.ajouter(std::make_shared<Define>(nomPropriete::icone, $6));
    }
    | DEFINE '(' LANGUE ')' '{' TEXT '}'  {
        programme.ajouter(std::make_shared<Define>(nomPropriete::langue, $6));
    }

bloc:
    TITLE {
        $$ = std::make_shared<BlocTitre>($1);
    }
    | IMAGE {
        $$ = std::make_shared<BlocImage>();
    }
    | PARAGRAPH {
        $$ = std::make_shared<BlocParagraphe>();
    }
    | VAR {
        std::cout << "variable contenant un bloc : ";
    }
blocuniv:
    UNIVPAGE {
        $$ = "page";
    }
    | UNIVTITLE {
        $$ = $1;
    }
    | UNIVPARAGRAPH {
        $$ = "paragraphe";
    }

expression:
    operation {
        //Modifier cette partie pour prendre en compte la structure avec expressions
        std::cout << "#-> " << $1 << std::endl;
    }

affectation:
    bloc {std::cout<<"1";} '[' operation ']' '.' STYLESELEC '=' '[' attributs ']' {
    }
    | bloc {std::cout<<"2";} '[' operation ']' '.' STYLESELEC '=' VAR {
    }
    | bloc {std::cout<<"3";} '[' operation ']' '.' nomattribut '=' NUMBER {
    }
    | bloc {std::cout<<"4";} '[' operation ']' '.' nomattribut '=' NUMBER PIXEL {
    }
    | bloc {std::cout<<"5";} '[' operation ']' '.' nomattribut '=' NUMBER '%' {
    }
    | bloc '[' operation ']' '.' nomattribut '=' couleur {
    }
    | bloc {std::cout<<"7";} '[' operation ']' '.' nomattribut '=' VAR {
    }
    | VAR '=' NUMBER {
        auto entier = std::make_shared<Entier>($3);
        auto affectation = std::make_shared<Affectation>($1, entier);
        programme.ajouter(affectation);
        std::cout << "Affectation à réaliser test"<< $1 <<" = " << $3 << std::endl;
    }
    | VAR '=' couleur {
        std::cout << "Affectation à réaliser "<< $1 <<" = " << std::endl;
        auto couleur = $3;
        std::cout << couleur->evaluate() << std::endl;
        auto affectation = std::make_shared<Affectation>($1, couleur);
        programme.ajouter(affectation);
    }
    | VAR '=' bloc TEXT {
        std::cout << "Affectation à réaliser "<< $1 <<" = " << std::endl;
        auto bloc = $3;
        bloc->setInnerTexte($4);
        auto affectation = std::make_shared<Affectation>($1, bloc);
        programme.ajouter(affectation);
    }
    | VAR '=' TITLEID '.' COULEURFOND {
        std::cout << "Affectation à réaliser via bloc "<< $1 <<" = bloc numero " << std::endl;
        //A COMPLETER
    }
    | VAR '=' bloc '[' operation ']' {
        std::cout << "Affectation à réaliser via bloc "<< $1 <<" = bloc numero " << $5 << std::endl;
        //A COMPLETER
    }
    | VAR '=' '[' attributs ']' {
        std::cout << "Affectation à réaliser "<< $1 <<" = " << std::endl;
        auto style = $4;
        auto affectation = std::make_shared<Affectation>($1, style);
        programme.ajouter(affectation);
    }
    | VAR '=' TITLEID {
        std::string Title = $3;
        int titlelevel=1;
        for(unsigned int i = 2;i<Title.length()-3;i++)
        {
            if(Title[i] == 'T') {
                titlelevel++;
            }
        }
        int titleid =std::stoi($3.substr(titlelevel+2,$3.length()-(titlelevel+3)));
        std::cout << "Affectation à réaliser "<< $1 <<" = h" << std::to_string(titlelevel)<<" id:"<<std::to_string(titleid) <<std::endl;

        auto selecteur = std::make_shared<SelecteurTitre>(titleid, programme.getInstruction(), titlelevel);

        auto affectation = std::make_shared<Affectation>($1, selecteur);
        programme.ajouter(affectation);

    }
    | VAR '=' IMAGEID {
        int imageid =std::stoi($3.substr(3,$3.length()-(4)));
        std::cout << "Affectation à réaliser "<< $1 <<" = img id:"<< imageid<< std::endl;

        auto selecteur = std::make_shared<SelecteurImage>(imageid, programme.getInstruction());

        auto affectation = std::make_shared<Affectation>($1, selecteur);
        programme.ajouter(affectation);
    }
    | VAR '=' PARAGRAPHID {
        int paraid =std::stoi($3.substr(3,$3.length()-(4)));
        std::cout << "Affectation à réaliser "<< $1 <<" = par id:"<< paraid << std::endl;
        auto selecteur = std::make_shared<SelecteurParagraphe>(paraid, programme.getInstruction());

        auto affectation = std::make_shared<Affectation>($1, selecteur);
        programme.ajouter(affectation);

    }
    | VAR '=' VAR {
        std::cout << "Affectation à réaliser de var a var"<< $1 << std::endl;
        //A COMPLETER
    }
    | VARATTRIBUT '=' '[' attributs ']' {
        int posofdot = $1.find('.');
        std::string nomvariable =  $1.substr(0,$1.length()-($1.length()-posofdot));
        std::string nomattribut =  $1.substr(posofdot+1,$1.length()-posofdot-1);

        auto style = $4;
        auto selecteurModifier = std::make_shared<SelecteurModifier>(nomvariable, style, nomattribut);
        programme.ajouter(selecteurModifier);
    }
    | VARATTRIBUT '=' VAR {
        int posofdot = $1.find('.');
        std::string nomvariable =  $1.substr(0,$1.length()-($1.length()-posofdot));
        std::string nomattribut =  $1.substr(posofdot+1,$1.length()-posofdot-1);
        auto affect = std::make_shared<SelecteurModifier>(nomvariable, $3, nomattribut);
        programme.ajouter(affect);
    }
    | VARATTRIBUT '=' couleur {
        int posofdot = $1.find('.');
        std::string nomvariable =  $1.substr(0,$1.length()-($1.length()-posofdot));
        std::string nomattribut =  $1.substr(posofdot+1,$1.length()-posofdot-1);
        std::cout << "Affectation à réaliser "<< nomvariable <<"."<< nomattribut << " = " << std::endl;

        auto couleur = $3;
        std::cout << couleur->evaluate() << std::endl;
        auto selecteurModifier = std::make_shared<SelecteurModifier>(nomvariable, couleur, nomattribut);
        programme.ajouter(selecteurModifier);
    }
    | VARATTRIBUT '=' number PIXEL {
        int posofdot = $1.find('.');
        std::string nomvariable =  $1.substr(0,$1.length()-($1.length()-posofdot));
        std::string nomattribut =  $1.substr(posofdot+1,$1.length()-posofdot-1);
        std::cout << "Affectation à réaliser "<< nomvariable <<"."<< nomattribut << " = " << $3 << std::endl;
        auto valeur = std::make_shared<Entier>($3);
        auto selecteurModifier = std::make_shared<SelecteurModifier>(nomvariable, valeur, nomattribut);
        programme.ajouter(selecteurModifier);

    }
    | VARATTRIBUT '=' number '%' {
        int posofdot = $1.find('.');
        std::string nomvariable =  $1.substr(0,$1.length()-($1.length()-posofdot));
        std::string nomattribut =  $1.substr(posofdot+1,$1.length()-posofdot-1);
        std::cout << "Affectation à réaliser "<< nomvariable <<"."<< nomattribut << " = " << $3 << std::endl;
        auto valeur = std::make_shared<Entier>($3);
        auto selecteurModifier = std::make_shared<SelecteurModifier>(nomvariable, valeur, nomattribut);
        programme.ajouter(selecteurModifier);
    }
    |  VARATTRIBUT '=' NUMBER {
        int posofdot = $1.find('.');
        std::string nomvariable =  $1.substr(0,$1.length()-($1.length()-posofdot));
        std::string nomattribut =  $1.substr(posofdot+1,$1.length()-posofdot-1);
        std::cout << "Affectation à réaliser "<< nomvariable <<"."<< nomattribut << " = " << $3 << std::endl;
        auto valeur = std::make_shared<Entier>($3);
        auto selecteurModifier = std::make_shared<SelecteurModifier>(nomvariable, valeur, nomattribut);
        programme.ajouter(selecteurModifier);
    }


operation:
    NUMBER {
        $$ = $1;
    }
    | VAR {
        //faire directement la conversion de var en int, 1 en attendant
        $$ = 1;
    }
    | '(' operation ')' {
        $$ = $2;
    }
    | operation '+' operation {
        $$ = $1 + $3;
    }
    | operation '-' operation {
        $$ = $1 - $3;
    }
    | operation '*' operation {
        $$ = $1 * $3;
    }
    | operation '/' operation {
        $$ = $1 / $3;
    }
    | '-' operation %prec NEG {
        $$ = - $2;
    }

value :
    couleur
    | number

comparaison:
    '(' comparaison ')' {}
    | value  EGAL value {
    }
    | value DIFFERENT value {
    }
    | value GREATER value {
    }
    | value LESSER value {
    }
    | value GREATEROREQUAL value {
    }
    | value LESSEROREQUAL value {
    }

%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
