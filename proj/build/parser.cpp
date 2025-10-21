// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 36 "parser/parser.yy"

    #include <iostream>
    #include <string>
    #include <algorithm>
    
    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex

#line 58 "/home/ebrio/Téléchargements/proj/build/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 150 "/home/ebrio/Téléchargements/proj/build/parser.cpp"

  /// Build a parser object.
   Parser :: Parser  (Scanner &scanner_yyarg, Driver &driver_yyarg, Programme &programme_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg),
      programme (programme_yyarg)
  {}

   Parser ::~ Parser  ()
  {}

   Parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_TITLE: // TITLE
      case symbol_kind::S_number: // number
      case symbol_kind::S_operation: // operation
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attribut: // attribut
        value.copy< std::shared_ptr<Attribut> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bloc: // bloc
        value.copy< std::shared_ptr<Bloc> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_couleur: // couleur
        value.copy< std::shared_ptr<Couleur> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attributs: // attributs
        value.copy< std::shared_ptr<Style> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_HEXANUMBER: // HEXANUMBER
      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_VARATTRIBUT: // VARATTRIBUT
      case symbol_kind::S_COULEURHEXA: // COULEURHEXA
      case symbol_kind::S_TITLEID: // TITLEID
      case symbol_kind::S_TEXT: // TEXT
      case symbol_kind::S_IMAGEID: // IMAGEID
      case symbol_kind::S_PARAGRAPHID: // PARAGRAPHID
      case symbol_kind::S_UNIVTITLE: // UNIVTITLE
      case symbol_kind::S_COMMENTAIRE: // COMMENTAIRE
      case symbol_kind::S_RANGE: // RANGE
      case symbol_kind::S_textebloc: // textebloc
      case symbol_kind::S_blocuniv: // blocuniv
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
   Parser ::symbol_kind_type
   Parser ::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
   Parser ::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_TITLE: // TITLE
      case symbol_kind::S_number: // number
      case symbol_kind::S_operation: // operation
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_attribut: // attribut
        value.move< std::shared_ptr<Attribut> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_bloc: // bloc
        value.move< std::shared_ptr<Bloc> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_couleur: // couleur
        value.move< std::shared_ptr<Couleur> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_attributs: // attributs
        value.move< std::shared_ptr<Style> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_HEXANUMBER: // HEXANUMBER
      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_VARATTRIBUT: // VARATTRIBUT
      case symbol_kind::S_COULEURHEXA: // COULEURHEXA
      case symbol_kind::S_TITLEID: // TITLEID
      case symbol_kind::S_TEXT: // TEXT
      case symbol_kind::S_IMAGEID: // IMAGEID
      case symbol_kind::S_PARAGRAPHID: // PARAGRAPHID
      case symbol_kind::S_UNIVTITLE: // UNIVTITLE
      case symbol_kind::S_COMMENTAIRE: // COMMENTAIRE
      case symbol_kind::S_RANGE: // RANGE
      case symbol_kind::S_textebloc: // textebloc
      case symbol_kind::S_blocuniv: // blocuniv
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
   Parser ::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
   Parser ::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

   Parser ::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

   Parser ::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
   Parser ::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
   Parser ::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

   Parser ::symbol_kind_type
   Parser ::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


   Parser ::symbol_kind_type
   Parser ::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
   Parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser ::symbol_kind_type
   Parser ::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_TITLE: // TITLE
      case symbol_kind::S_number: // number
      case symbol_kind::S_operation: // operation
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attribut: // attribut
        value.YY_MOVE_OR_COPY< std::shared_ptr<Attribut> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bloc: // bloc
        value.YY_MOVE_OR_COPY< std::shared_ptr<Bloc> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_couleur: // couleur
        value.YY_MOVE_OR_COPY< std::shared_ptr<Couleur> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attributs: // attributs
        value.YY_MOVE_OR_COPY< std::shared_ptr<Style> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_HEXANUMBER: // HEXANUMBER
      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_VARATTRIBUT: // VARATTRIBUT
      case symbol_kind::S_COULEURHEXA: // COULEURHEXA
      case symbol_kind::S_TITLEID: // TITLEID
      case symbol_kind::S_TEXT: // TEXT
      case symbol_kind::S_IMAGEID: // IMAGEID
      case symbol_kind::S_PARAGRAPHID: // PARAGRAPHID
      case symbol_kind::S_UNIVTITLE: // UNIVTITLE
      case symbol_kind::S_COMMENTAIRE: // COMMENTAIRE
      case symbol_kind::S_RANGE: // RANGE
      case symbol_kind::S_textebloc: // textebloc
      case symbol_kind::S_blocuniv: // blocuniv
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_TITLE: // TITLE
      case symbol_kind::S_number: // number
      case symbol_kind::S_operation: // operation
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attribut: // attribut
        value.move< std::shared_ptr<Attribut> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bloc: // bloc
        value.move< std::shared_ptr<Bloc> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_couleur: // couleur
        value.move< std::shared_ptr<Couleur> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attributs: // attributs
        value.move< std::shared_ptr<Style> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_HEXANUMBER: // HEXANUMBER
      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_VARATTRIBUT: // VARATTRIBUT
      case symbol_kind::S_COULEURHEXA: // COULEURHEXA
      case symbol_kind::S_TITLEID: // TITLEID
      case symbol_kind::S_TEXT: // TEXT
      case symbol_kind::S_IMAGEID: // IMAGEID
      case symbol_kind::S_PARAGRAPHID: // PARAGRAPHID
      case symbol_kind::S_UNIVTITLE: // UNIVTITLE
      case symbol_kind::S_COMMENTAIRE: // COMMENTAIRE
      case symbol_kind::S_RANGE: // RANGE
      case symbol_kind::S_textebloc: // textebloc
      case symbol_kind::S_blocuniv: // blocuniv
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_TITLE: // TITLE
      case symbol_kind::S_number: // number
      case symbol_kind::S_operation: // operation
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_attribut: // attribut
        value.copy< std::shared_ptr<Attribut> > (that.value);
        break;

      case symbol_kind::S_bloc: // bloc
        value.copy< std::shared_ptr<Bloc> > (that.value);
        break;

      case symbol_kind::S_couleur: // couleur
        value.copy< std::shared_ptr<Couleur> > (that.value);
        break;

      case symbol_kind::S_attributs: // attributs
        value.copy< std::shared_ptr<Style> > (that.value);
        break;

      case symbol_kind::S_HEXANUMBER: // HEXANUMBER
      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_VARATTRIBUT: // VARATTRIBUT
      case symbol_kind::S_COULEURHEXA: // COULEURHEXA
      case symbol_kind::S_TITLEID: // TITLEID
      case symbol_kind::S_TEXT: // TEXT
      case symbol_kind::S_IMAGEID: // IMAGEID
      case symbol_kind::S_PARAGRAPHID: // PARAGRAPHID
      case symbol_kind::S_UNIVTITLE: // UNIVTITLE
      case symbol_kind::S_COMMENTAIRE: // COMMENTAIRE
      case symbol_kind::S_RANGE: // RANGE
      case symbol_kind::S_textebloc: // textebloc
      case symbol_kind::S_blocuniv: // blocuniv
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_TITLE: // TITLE
      case symbol_kind::S_number: // number
      case symbol_kind::S_operation: // operation
        value.move< int > (that.value);
        break;

      case symbol_kind::S_attribut: // attribut
        value.move< std::shared_ptr<Attribut> > (that.value);
        break;

      case symbol_kind::S_bloc: // bloc
        value.move< std::shared_ptr<Bloc> > (that.value);
        break;

      case symbol_kind::S_couleur: // couleur
        value.move< std::shared_ptr<Couleur> > (that.value);
        break;

      case symbol_kind::S_attributs: // attributs
        value.move< std::shared_ptr<Style> > (that.value);
        break;

      case symbol_kind::S_HEXANUMBER: // HEXANUMBER
      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_VARATTRIBUT: // VARATTRIBUT
      case symbol_kind::S_COULEURHEXA: // COULEURHEXA
      case symbol_kind::S_TITLEID: // TITLEID
      case symbol_kind::S_TEXT: // TEXT
      case symbol_kind::S_IMAGEID: // IMAGEID
      case symbol_kind::S_PARAGRAPHID: // PARAGRAPHID
      case symbol_kind::S_UNIVTITLE: // UNIVTITLE
      case symbol_kind::S_COMMENTAIRE: // COMMENTAIRE
      case symbol_kind::S_RANGE: // RANGE
      case symbol_kind::S_textebloc: // textebloc
      case symbol_kind::S_blocuniv: // blocuniv
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
   Parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser ::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
   Parser ::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser ::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::operator() ()
  {
    return parse ();
  }

  int
   Parser ::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_TITLE: // TITLE
      case symbol_kind::S_number: // number
      case symbol_kind::S_operation: // operation
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_attribut: // attribut
        yylhs.value.emplace< std::shared_ptr<Attribut> > ();
        break;

      case symbol_kind::S_bloc: // bloc
        yylhs.value.emplace< std::shared_ptr<Bloc> > ();
        break;

      case symbol_kind::S_couleur: // couleur
        yylhs.value.emplace< std::shared_ptr<Couleur> > ();
        break;

      case symbol_kind::S_attributs: // attributs
        yylhs.value.emplace< std::shared_ptr<Style> > ();
        break;

      case symbol_kind::S_HEXANUMBER: // HEXANUMBER
      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_VARATTRIBUT: // VARATTRIBUT
      case symbol_kind::S_COULEURHEXA: // COULEURHEXA
      case symbol_kind::S_TITLEID: // TITLEID
      case symbol_kind::S_TEXT: // TEXT
      case symbol_kind::S_IMAGEID: // IMAGEID
      case symbol_kind::S_PARAGRAPHID: // PARAGRAPHID
      case symbol_kind::S_UNIVTITLE: // UNIVTITLE
      case symbol_kind::S_COMMENTAIRE: // COMMENTAIRE
      case symbol_kind::S_RANGE: // RANGE
      case symbol_kind::S_textebloc: // textebloc
      case symbol_kind::S_blocuniv: // blocuniv
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 4: // programme: NL END
#line 120 "parser/parser.yy"
             {
        YYACCEPT;
    }
#line 916 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 5: // programme: END
#line 123 "parser/parser.yy"
          {
        YYACCEPT;
    }
#line 924 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 14: // pour: POUR VAR RANGE '+' number ':' pourinterne FINI
#line 140 "parser/parser.yy"
                                                  {
    }
#line 931 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 15: // pour: POUR VAR RANGE '-' number ':' NL pourinterne FINI
#line 142 "parser/parser.yy"
                                                       {
    }
#line 938 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 16: // pour: POUR VAR RANGE '+' number ':' NL pourinterne FINI
#line 144 "parser/parser.yy"
                                                       {
    }
#line 945 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 17: // pour: POUR VAR RANGE '-' number ':' pourinterne FINI
#line 146 "parser/parser.yy"
                                                    {
    }
#line 952 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 18: // instruction: pour
#line 150 "parser/parser.yy"
         {}
#line 958 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 19: // instruction: si
#line 151 "parser/parser.yy"
         {}
#line 964 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 20: // instruction: expression
#line 152 "parser/parser.yy"
                  {
        YYACCEPT;
    }
#line 972 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 21: // instruction: affectation
#line 155 "parser/parser.yy"
                  {
    }
#line 979 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 22: // instruction: bloc '[' attributs ']' textebloc
#line 157 "parser/parser.yy"
                                      {
        std::cout<<yystack_[0].value.as < std::string > ()<<std::endl;
        yystack_[4].value.as < std::shared_ptr<Bloc> > ()->setInnerTexte(yystack_[0].value.as < std::string > ());
        yystack_[4].value.as < std::shared_ptr<Bloc> > ()->setStyle(yystack_[2].value.as < std::shared_ptr<Style> > ());
        programme.ajouter(yystack_[4].value.as < std::shared_ptr<Bloc> > ());
    }
#line 990 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 23: // instruction: bloc textebloc
#line 163 "parser/parser.yy"
                    {
        yystack_[1].value.as < std::shared_ptr<Bloc> > ()->setInnerTexte(yystack_[0].value.as < std::string > ());
        programme.ajouter(yystack_[1].value.as < std::shared_ptr<Bloc> > ());
    }
#line 999 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 24: // instruction: style
#line 167 "parser/parser.yy"
            {}
#line 1005 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 25: // instruction: parametre
#line 169 "parser/parser.yy"
                {}
#line 1011 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 26: // instruction: COMMENTAIRE
#line 171 "parser/parser.yy"
                  {
        programme.ajouter(std::make_shared<Commentaire>(yystack_[0].value.as < std::string > ()));
    }
#line 1019 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 27: // textebloc: TEXT textebloc
#line 176 "parser/parser.yy"
                   {
        yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + yystack_[0].value.as < std::string > ();
    }
#line 1027 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 28: // textebloc: operation textebloc
#line 179 "parser/parser.yy"
                          {
        std::cout<<std::to_string(yystack_[1].value.as < int > ());
        yylhs.value.as < std::string > () = std::to_string(yystack_[1].value.as < int > ()) + yystack_[0].value.as < std::string > ();
    }
#line 1036 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 29: // textebloc: VAR textebloc
#line 183 "parser/parser.yy"
                    {
        //a completer
    }
#line 1044 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 30: // textebloc: TEXT
#line 186 "parser/parser.yy"
           {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
    }
#line 1052 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 31: // textebloc: operation
#line 189 "parser/parser.yy"
                {
        std::cout<<std::to_string(yystack_[0].value.as < int > ());
        yylhs.value.as < std::string > () = std::to_string(yystack_[0].value.as < int > ());
    }
#line 1061 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 32: // textebloc: VAR
#line 193 "parser/parser.yy"
          {
        //a completer
    }
#line 1069 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 33: // style: STYLE '(' blocuniv ')' '[' attributs ']'
#line 198 "parser/parser.yy"
                                             {
        programme.ajouter(std::make_shared<StyleBloc>(yystack_[4].value.as < std::string > (), yystack_[1].value.as < std::shared_ptr<Style> > ()));
    }
#line 1077 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 34: // style: STYLE '(' blocuniv ')' '[' NL attributs ']'
#line 201 "parser/parser.yy"
                                                  {
        programme.ajouter(std::make_shared<StyleBloc>(yystack_[5].value.as < std::string > (), yystack_[1].value.as < std::shared_ptr<Style> > ()));
    }
#line 1085 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 40: // attribut: LARGEUR ':' number
#line 213 "parser/parser.yy"
                       {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::largeur, yystack_[0].value.as < int > ());
        yylhs.value.as < std::shared_ptr<Attribut> > () = attribut;
    }
#line 1094 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 41: // attribut: LARGEUR ':' number PIXEL
#line 217 "parser/parser.yy"
                               { // on pourrait factoriser px mais la compléxité rajouté me semble peut nécessaire pour l'utilisation faite
        auto attribut = std::make_shared<AttributEntier>(TAttributs::largeur, yystack_[1].value.as < int > (), "px");
        yylhs.value.as < std::shared_ptr<Attribut> > () = attribut;
    }
#line 1103 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 42: // attribut: HAUTEUR ':' number
#line 221 "parser/parser.yy"
                         {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::hauteur, yystack_[0].value.as < int > ());
        yylhs.value.as < std::shared_ptr<Attribut> > () = attribut;
    }
#line 1112 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 43: // attribut: HAUTEUR ':' number PIXEL
#line 225 "parser/parser.yy"
                               {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::hauteur, yystack_[1].value.as < int > (), "px");
        yylhs.value.as < std::shared_ptr<Attribut> > () = attribut;
    }
#line 1121 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 44: // attribut: OPACITE ':' number
#line 229 "parser/parser.yy"
                         {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::opacite, yystack_[0].value.as < int > ());
        yylhs.value.as < std::shared_ptr<Attribut> > () = attribut;
    }
#line 1130 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 45: // attribut: OPACITE ':' number '%'
#line 233 "parser/parser.yy"
                             {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::opacite, yystack_[1].value.as < int > (), "%");
        yylhs.value.as < std::shared_ptr<Attribut> > () = attribut;
    }
#line 1139 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 46: // attribut: COULEURTEXTE ':' couleur
#line 237 "parser/parser.yy"
                               {
        auto attribut = std::make_shared<AttributCouleur>(TAttributs::couleurTexte, yystack_[0].value.as < std::shared_ptr<Couleur> > ());
        yylhs.value.as < std::shared_ptr<Attribut> > () = attribut;
    }
#line 1148 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 47: // attribut: COULEURFOND ':' couleur
#line 241 "parser/parser.yy"
                              {
        auto attribut = std::make_shared<AttributCouleur>(TAttributs::couleurFond, yystack_[0].value.as < std::shared_ptr<Couleur> > ());
        yylhs.value.as < std::shared_ptr<Attribut> > () = attribut;
    }
#line 1157 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 48: // attribut: LARGEUR ':' VAR
#line 245 "parser/parser.yy"
                      {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::largeur, 1);
        yylhs.value.as < std::shared_ptr<Attribut> > () = attribut;
    }
#line 1166 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 49: // attribut: LARGEUR ':' VAR PIXEL
#line 249 "parser/parser.yy"
                            { // on pourrait factoriser px mais la compléxité rajouté me semble peut nécessaire pour l'utilisation faite
        auto attribut = std::make_shared<AttributEntier>(TAttributs::largeur, 1, "px");
        yylhs.value.as < std::shared_ptr<Attribut> > () = attribut;
    }
#line 1175 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 50: // attribut: HAUTEUR ':' VAR
#line 253 "parser/parser.yy"
                      {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::hauteur, 1);
        yylhs.value.as < std::shared_ptr<Attribut> > () = attribut;
    }
#line 1184 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 51: // attribut: HAUTEUR ':' VAR PIXEL
#line 257 "parser/parser.yy"
                            {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::hauteur, 1, "px");
        yylhs.value.as < std::shared_ptr<Attribut> > () = attribut;
    }
#line 1193 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 52: // attribut: OPACITE ':' VAR
#line 261 "parser/parser.yy"
                      {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::opacite, 1);
        yylhs.value.as < std::shared_ptr<Attribut> > () = attribut;
    }
#line 1202 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 53: // attribut: OPACITE ':' VAR '%'
#line 265 "parser/parser.yy"
                          {
        auto attribut = std::make_shared<AttributEntier>(TAttributs::opacite, 1, "%");
        yylhs.value.as < std::shared_ptr<Attribut> > () = attribut;
    }
#line 1211 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 54: // attribut: COULEURTEXTE ':' VAR
#line 269 "parser/parser.yy"
                           {
        auto coultest = std::make_shared<Couleur>("0","0","0",true);
        auto attribut = std::make_shared<AttributCouleur>(TAttributs::couleurTexte, coultest);
        yylhs.value.as < std::shared_ptr<Attribut> > () = attribut;
    }
#line 1221 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 55: // attribut: COULEURFOND ':' VAR
#line 274 "parser/parser.yy"
                          {
        auto coultest = std::make_shared<Couleur>("0","0","0",true);
        auto attribut = std::make_shared<AttributCouleur>(TAttributs::couleurFond, coultest);
        yylhs.value.as < std::shared_ptr<Attribut> > () = attribut;
    }
#line 1231 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 56: // couleur: COULEUR '(' number ',' number ',' number ')'
#line 282 "parser/parser.yy"
                                                 {
        if(yystack_[5].value.as < int > ()>=0 && yystack_[5].value.as < int > ()<=255 && yystack_[3].value.as < int > ()>=0 && yystack_[3].value.as < int > ()<=255 && yystack_[1].value.as < int > ()>=0 && yystack_[1].value.as < int > ()<=255) { // pourrait être traité dans l'ast
            yylhs.value.as < std::shared_ptr<Couleur> > () = std::make_shared<Couleur>(std::to_string(yystack_[5].value.as < int > ()), std::to_string(yystack_[3].value.as < int > ()), std::to_string(yystack_[1].value.as < int > ()), false);
            
            std::cout <<  "couleur(" << yystack_[5].value.as < int > () << "," << yystack_[3].value.as < int > () << "," << yystack_[1].value.as < int > () << ")";
        }
        else
        {
            std::cout <<  "erreur";
        }
    }
#line 1247 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 57: // couleur: COULEURHEXA
#line 293 "parser/parser.yy"
                  {
        std::string r = yystack_[0].value.as < std::string > ().substr(1,2);
        std::string g = yystack_[0].value.as < std::string > ().substr(3,2); 
        std::string b = yystack_[0].value.as < std::string > ().substr(5,2);

        yylhs.value.as < std::shared_ptr<Couleur> > () = std::make_shared<Couleur>(r, g, b, true);

        std::cout << "couleur(" << std::stoi(yystack_[0].value.as < std::string > ().substr(1,2),0,16) << "," << std::stoi(yystack_[0].value.as < std::string > ().substr(3,2),0,16)  << "," << std::stoi(yystack_[0].value.as < std::string > ().substr(5,2),0,16)  << ")"; 
    }
#line 1261 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 58: // attributs: attribut ',' attributs
#line 304 "parser/parser.yy"
                           {
        auto style = yystack_[0].value.as < std::shared_ptr<Style> > ();
        style->ajouterAttr(yystack_[2].value.as < std::shared_ptr<Attribut> > ());
        yylhs.value.as < std::shared_ptr<Style> > () = style;
    }
#line 1271 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 59: // attributs: attribut NL attributs
#line 309 "parser/parser.yy"
                            {
        auto style = yystack_[0].value.as < std::shared_ptr<Style> > ();
        style->ajouterAttr(yystack_[2].value.as < std::shared_ptr<Attribut> > ());
        yylhs.value.as < std::shared_ptr<Style> > () = style;
    }
#line 1281 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 60: // attributs: attribut NL
#line 314 "parser/parser.yy"
                  {
        auto style = std::make_shared<Style>();
        style->ajouterAttr(yystack_[1].value.as < std::shared_ptr<Attribut> > ());
        yylhs.value.as < std::shared_ptr<Style> > () = style;
    }
#line 1291 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 61: // attributs: attribut
#line 319 "parser/parser.yy"
               {
        auto style = std::make_shared<Style>();
        style->ajouterAttr(yystack_[0].value.as < std::shared_ptr<Attribut> > ());
        yylhs.value.as < std::shared_ptr<Style> > () = style;
    }
#line 1301 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 62: // number: NUMBER
#line 326 "parser/parser.yy"
           {
        yylhs.value.as < int > () = yystack_[0].value.as < int > ();
    }
#line 1309 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 63: // number: VAR
#line 329 "parser/parser.yy"
          {
        std::cout<< "variable de nombre :";
    }
#line 1317 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 64: // number: VARATTRIBUT
#line 332 "parser/parser.yy"
                  {
        std::cout << "attribut de variable de nombre :" <<yystack_[0].value.as < std::string > ();
    }
#line 1325 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 65: // parametre: TITREPAGE TEXT
#line 338 "parser/parser.yy"
                   {
        programme.ajouter(std::make_shared<Define>(nomPropriete::titre, yystack_[0].value.as < std::string > ()));
    }
#line 1333 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 66: // parametre: DEFINE '(' ENCODAGE ')' '{' TEXT '}'
#line 341 "parser/parser.yy"
                                            {
        programme.ajouter(std::make_shared<Define>(nomPropriete::encodage, yystack_[1].value.as < std::string > ()));
    }
#line 1341 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 67: // parametre: DEFINE '(' ICONE ')' '{' TEXT '}'
#line 344 "parser/parser.yy"
                                         {
        programme.ajouter(std::make_shared<Define>(nomPropriete::icone, yystack_[1].value.as < std::string > ()));
    }
#line 1349 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 68: // parametre: DEFINE '(' CSS ')' '{' TEXT '}'
#line 347 "parser/parser.yy"
                                       {
        programme.ajouter(std::make_shared<Define>(nomPropriete::icone, yystack_[1].value.as < std::string > ()));
    }
#line 1357 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 69: // parametre: DEFINE '(' LANGUE ')' '{' TEXT '}'
#line 350 "parser/parser.yy"
                                          {
        programme.ajouter(std::make_shared<Define>(nomPropriete::langue, yystack_[1].value.as < std::string > ()));
    }
#line 1365 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 70: // bloc: TITLE
#line 355 "parser/parser.yy"
          {
        yylhs.value.as < std::shared_ptr<Bloc> > () = std::make_shared<BlocTitre>(yystack_[0].value.as < int > ());
    }
#line 1373 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 71: // bloc: IMAGE
#line 358 "parser/parser.yy"
            {
        yylhs.value.as < std::shared_ptr<Bloc> > () = std::make_shared<BlocImage>();
    }
#line 1381 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 72: // bloc: PARAGRAPH
#line 361 "parser/parser.yy"
                {
        yylhs.value.as < std::shared_ptr<Bloc> > () = std::make_shared<BlocParagraphe>();
    }
#line 1389 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 73: // bloc: VAR
#line 364 "parser/parser.yy"
          {
        std::cout << "variable contenant un bloc : ";
    }
#line 1397 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 74: // blocuniv: UNIVPAGE
#line 368 "parser/parser.yy"
             {
        yylhs.value.as < std::string > () = "page";
    }
#line 1405 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 75: // blocuniv: UNIVTITLE
#line 371 "parser/parser.yy"
                {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
    }
#line 1413 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 76: // blocuniv: UNIVPARAGRAPH
#line 374 "parser/parser.yy"
                    {
        yylhs.value.as < std::string > () = "paragraphe";
    }
#line 1421 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 77: // expression: operation
#line 379 "parser/parser.yy"
              {
        //Modifier cette partie pour prendre en compte la structure avec expressions
        std::cout << "#-> " << yystack_[0].value.as < int > () << std::endl;
    }
#line 1430 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 78: // $@1: %empty
#line 385 "parser/parser.yy"
         {std::cout<<"1";}
#line 1436 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 79: // affectation: bloc $@1 '[' operation ']' '.' STYLESELEC '=' '[' attributs ']'
#line 385 "parser/parser.yy"
                                                                                  {
    }
#line 1443 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 80: // $@2: %empty
#line 387 "parser/parser.yy"
           {std::cout<<"2";}
#line 1449 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 81: // affectation: bloc $@2 '[' operation ']' '.' STYLESELEC '=' VAR
#line 387 "parser/parser.yy"
                                                                      {
    }
#line 1456 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 82: // $@3: %empty
#line 389 "parser/parser.yy"
           {std::cout<<"3";}
#line 1462 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 83: // affectation: bloc $@3 '[' operation ']' '.' nomattribut '=' NUMBER
#line 389 "parser/parser.yy"
                                                                          {
    }
#line 1469 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 84: // $@4: %empty
#line 391 "parser/parser.yy"
           {std::cout<<"4";}
#line 1475 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 85: // affectation: bloc $@4 '[' operation ']' '.' nomattribut '=' NUMBER PIXEL
#line 391 "parser/parser.yy"
                                                                                {
    }
#line 1482 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 86: // $@5: %empty
#line 393 "parser/parser.yy"
           {std::cout<<"5";}
#line 1488 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 87: // affectation: bloc $@5 '[' operation ']' '.' nomattribut '=' NUMBER '%'
#line 393 "parser/parser.yy"
                                                                              {
    }
#line 1495 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 88: // affectation: bloc '[' operation ']' '.' nomattribut '=' couleur
#line 395 "parser/parser.yy"
                                                         {
    }
#line 1502 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 89: // $@6: %empty
#line 397 "parser/parser.yy"
           {std::cout<<"7";}
#line 1508 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 90: // affectation: bloc $@6 '[' operation ']' '.' nomattribut '=' VAR
#line 397 "parser/parser.yy"
                                                                       {
    }
#line 1515 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 91: // affectation: VAR '=' NUMBER
#line 399 "parser/parser.yy"
                     {
        auto entier = std::make_shared<Entier>(yystack_[0].value.as < int > ());
        auto affectation = std::make_shared<Affectation>(yystack_[2].value.as < std::string > (), entier);
        programme.ajouter(affectation);
        std::cout << "Affectation à réaliser test"<< yystack_[2].value.as < std::string > () <<" = " << yystack_[0].value.as < int > () << std::endl;
    }
#line 1526 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 92: // affectation: VAR '=' couleur
#line 405 "parser/parser.yy"
                      {
        std::cout << "Affectation à réaliser "<< yystack_[2].value.as < std::string > () <<" = " << std::endl;
        auto couleur = yystack_[0].value.as < std::shared_ptr<Couleur> > ();
        std::cout << couleur->evaluate() << std::endl;
        auto affectation = std::make_shared<Affectation>(yystack_[2].value.as < std::string > (), couleur);
        programme.ajouter(affectation);
    }
#line 1538 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 93: // affectation: VAR '=' bloc TEXT
#line 412 "parser/parser.yy"
                        {
        std::cout << "Affectation à réaliser "<< yystack_[3].value.as < std::string > () <<" = " << std::endl;
        auto bloc = yystack_[1].value.as < std::shared_ptr<Bloc> > ();
        bloc->setInnerTexte(yystack_[0].value.as < std::string > ());
        auto affectation = std::make_shared<Affectation>(yystack_[3].value.as < std::string > (), bloc);
        programme.ajouter(affectation);
    }
#line 1550 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 94: // affectation: VAR '=' TITLEID '.' COULEURFOND
#line 419 "parser/parser.yy"
                                      {
        std::cout << "Affectation à réaliser via bloc "<< yystack_[4].value.as < std::string > () <<" = bloc numero " << std::endl;
        //A COMPLETER
    }
#line 1559 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 95: // affectation: VAR '=' bloc '[' operation ']'
#line 423 "parser/parser.yy"
                                     {
        std::cout << "Affectation à réaliser via bloc "<< yystack_[5].value.as < std::string > () <<" = bloc numero " << yystack_[1].value.as < int > () << std::endl;
        //A COMPLETER
    }
#line 1568 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 96: // affectation: VAR '=' '[' attributs ']'
#line 427 "parser/parser.yy"
                                {
        std::cout << "Affectation à réaliser "<< yystack_[4].value.as < std::string > () <<" = " << std::endl;
        auto style = yystack_[1].value.as < std::shared_ptr<Style> > ();
        auto affectation = std::make_shared<Affectation>(yystack_[4].value.as < std::string > (), style);
        programme.ajouter(affectation);
    }
#line 1579 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 97: // affectation: VAR '=' TITLEID
#line 433 "parser/parser.yy"
                      {
        std::string Title = yystack_[0].value.as < std::string > ();
        int titlelevel=1;
        for(unsigned int i = 2;i<Title.length()-3;i++)
        {
            if(Title[i] == 'T') {
                titlelevel++;
            }
        }
        int titleid =std::stoi(yystack_[0].value.as < std::string > ().substr(titlelevel+2,yystack_[0].value.as < std::string > ().length()-(titlelevel+3)));
        std::cout << "Affectation à réaliser "<< yystack_[2].value.as < std::string > () <<" = h" << std::to_string(titlelevel)<<" id:"<<std::to_string(titleid) <<std::endl;

        auto selecteur = std::make_shared<SelecteurTitre>(titleid, programme.getInstruction(), titlelevel);

        auto affectation = std::make_shared<Affectation>(yystack_[2].value.as < std::string > (), selecteur);
        programme.ajouter(affectation);

    }
#line 1602 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 98: // affectation: VAR '=' IMAGEID
#line 451 "parser/parser.yy"
                      {
        int imageid =std::stoi(yystack_[0].value.as < std::string > ().substr(3,yystack_[0].value.as < std::string > ().length()-(4)));
        std::cout << "Affectation à réaliser "<< yystack_[2].value.as < std::string > () <<" = img id:"<< imageid<< std::endl;

        auto selecteur = std::make_shared<SelecteurImage>(imageid, programme.getInstruction());

        auto affectation = std::make_shared<Affectation>(yystack_[2].value.as < std::string > (), selecteur);
        programme.ajouter(affectation);
    }
#line 1616 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 99: // affectation: VAR '=' PARAGRAPHID
#line 460 "parser/parser.yy"
                          {
        int paraid =std::stoi(yystack_[0].value.as < std::string > ().substr(3,yystack_[0].value.as < std::string > ().length()-(4)));
        std::cout << "Affectation à réaliser "<< yystack_[2].value.as < std::string > () <<" = par id:"<< paraid << std::endl;
        auto selecteur = std::make_shared<SelecteurParagraphe>(paraid, programme.getInstruction());

        auto affectation = std::make_shared<Affectation>(yystack_[2].value.as < std::string > (), selecteur);
        programme.ajouter(affectation);

    }
#line 1630 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 100: // affectation: VAR '=' VAR
#line 469 "parser/parser.yy"
                  {
        std::cout << "Affectation à réaliser de var a var"<< yystack_[2].value.as < std::string > () << std::endl;
        //A COMPLETER
    }
#line 1639 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 101: // affectation: VARATTRIBUT '=' '[' attributs ']'
#line 473 "parser/parser.yy"
                                        {
        int posofdot = yystack_[4].value.as < std::string > ().find('.');
        std::string nomvariable =  yystack_[4].value.as < std::string > ().substr(0,yystack_[4].value.as < std::string > ().length()-(yystack_[4].value.as < std::string > ().length()-posofdot));
        std::string nomattribut =  yystack_[4].value.as < std::string > ().substr(posofdot+1,yystack_[4].value.as < std::string > ().length()-posofdot-1);

        auto style = yystack_[1].value.as < std::shared_ptr<Style> > ();
        auto selecteurModifier = std::make_shared<SelecteurModifier>(nomvariable, style, nomattribut);
        programme.ajouter(selecteurModifier);
    }
#line 1653 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 102: // affectation: VARATTRIBUT '=' VAR
#line 482 "parser/parser.yy"
                          {
        int posofdot = yystack_[2].value.as < std::string > ().find('.');
        std::string nomvariable =  yystack_[2].value.as < std::string > ().substr(0,yystack_[2].value.as < std::string > ().length()-(yystack_[2].value.as < std::string > ().length()-posofdot));
        std::string nomattribut =  yystack_[2].value.as < std::string > ().substr(posofdot+1,yystack_[2].value.as < std::string > ().length()-posofdot-1);
        auto affect = std::make_shared<SelecteurModifier>(nomvariable, yystack_[0].value.as < std::string > (), nomattribut);
        programme.ajouter(affect);
    }
#line 1665 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 103: // affectation: VARATTRIBUT '=' couleur
#line 489 "parser/parser.yy"
                              {
        int posofdot = yystack_[2].value.as < std::string > ().find('.');
        std::string nomvariable =  yystack_[2].value.as < std::string > ().substr(0,yystack_[2].value.as < std::string > ().length()-(yystack_[2].value.as < std::string > ().length()-posofdot));
        std::string nomattribut =  yystack_[2].value.as < std::string > ().substr(posofdot+1,yystack_[2].value.as < std::string > ().length()-posofdot-1);
        std::cout << "Affectation à réaliser "<< nomvariable <<"."<< nomattribut << " = " << std::endl;

        auto couleur = yystack_[0].value.as < std::shared_ptr<Couleur> > ();
        std::cout << couleur->evaluate() << std::endl;
        auto selecteurModifier = std::make_shared<SelecteurModifier>(nomvariable, couleur, nomattribut);
        programme.ajouter(selecteurModifier);
    }
#line 1681 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 104: // affectation: VARATTRIBUT '=' number PIXEL
#line 500 "parser/parser.yy"
                                   {
        int posofdot = yystack_[3].value.as < std::string > ().find('.');
        std::string nomvariable =  yystack_[3].value.as < std::string > ().substr(0,yystack_[3].value.as < std::string > ().length()-(yystack_[3].value.as < std::string > ().length()-posofdot));
        std::string nomattribut =  yystack_[3].value.as < std::string > ().substr(posofdot+1,yystack_[3].value.as < std::string > ().length()-posofdot-1);
        std::cout << "Affectation à réaliser "<< nomvariable <<"."<< nomattribut << " = " << yystack_[1].value.as < int > () << std::endl;
        auto valeur = std::make_shared<Entier>(yystack_[1].value.as < int > ());
        auto selecteurModifier = std::make_shared<SelecteurModifier>(nomvariable, valeur, nomattribut);
        programme.ajouter(selecteurModifier);

    }
#line 1696 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 105: // affectation: VARATTRIBUT '=' number '%'
#line 510 "parser/parser.yy"
                                 {
        int posofdot = yystack_[3].value.as < std::string > ().find('.');
        std::string nomvariable =  yystack_[3].value.as < std::string > ().substr(0,yystack_[3].value.as < std::string > ().length()-(yystack_[3].value.as < std::string > ().length()-posofdot));
        std::string nomattribut =  yystack_[3].value.as < std::string > ().substr(posofdot+1,yystack_[3].value.as < std::string > ().length()-posofdot-1);
        std::cout << "Affectation à réaliser "<< nomvariable <<"."<< nomattribut << " = " << yystack_[1].value.as < int > () << std::endl;
        auto valeur = std::make_shared<Entier>(yystack_[1].value.as < int > ());
        auto selecteurModifier = std::make_shared<SelecteurModifier>(nomvariable, valeur, nomattribut);
        programme.ajouter(selecteurModifier);
    }
#line 1710 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 106: // affectation: VARATTRIBUT '=' NUMBER
#line 519 "parser/parser.yy"
                              {
        int posofdot = yystack_[2].value.as < std::string > ().find('.');
        std::string nomvariable =  yystack_[2].value.as < std::string > ().substr(0,yystack_[2].value.as < std::string > ().length()-(yystack_[2].value.as < std::string > ().length()-posofdot));
        std::string nomattribut =  yystack_[2].value.as < std::string > ().substr(posofdot+1,yystack_[2].value.as < std::string > ().length()-posofdot-1);
        std::cout << "Affectation à réaliser "<< nomvariable <<"."<< nomattribut << " = " << yystack_[0].value.as < int > () << std::endl;
        auto valeur = std::make_shared<Entier>(yystack_[0].value.as < int > ());
        auto selecteurModifier = std::make_shared<SelecteurModifier>(nomvariable, valeur, nomattribut);
        programme.ajouter(selecteurModifier);
    }
#line 1724 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 107: // operation: NUMBER
#line 531 "parser/parser.yy"
           {
        yylhs.value.as < int > () = yystack_[0].value.as < int > ();
    }
#line 1732 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 108: // operation: VAR
#line 534 "parser/parser.yy"
          {
        //faire directement la conversion de var en int, 1 en attendant
        yylhs.value.as < int > () = 1;
    }
#line 1741 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 109: // operation: '(' operation ')'
#line 538 "parser/parser.yy"
                        {
        yylhs.value.as < int > () = yystack_[1].value.as < int > ();
    }
#line 1749 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 110: // operation: operation '+' operation
#line 541 "parser/parser.yy"
                              {
        yylhs.value.as < int > () = yystack_[2].value.as < int > () + yystack_[0].value.as < int > ();
    }
#line 1757 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 111: // operation: operation '-' operation
#line 544 "parser/parser.yy"
                              {
        yylhs.value.as < int > () = yystack_[2].value.as < int > () - yystack_[0].value.as < int > ();
    }
#line 1765 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 112: // operation: operation '*' operation
#line 547 "parser/parser.yy"
                              {
        yylhs.value.as < int > () = yystack_[2].value.as < int > () * yystack_[0].value.as < int > ();
    }
#line 1773 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 113: // operation: operation '/' operation
#line 550 "parser/parser.yy"
                              {
        yylhs.value.as < int > () = yystack_[2].value.as < int > () / yystack_[0].value.as < int > ();
    }
#line 1781 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 114: // operation: '-' operation
#line 553 "parser/parser.yy"
                              {
        yylhs.value.as < int > () = - yystack_[0].value.as < int > ();
    }
#line 1789 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 117: // comparaison: '(' comparaison ')'
#line 562 "parser/parser.yy"
                        {}
#line 1795 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 118: // comparaison: value EGAL value
#line 563 "parser/parser.yy"
                        {
    }
#line 1802 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 119: // comparaison: value DIFFERENT value
#line 565 "parser/parser.yy"
                            {
    }
#line 1809 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 120: // comparaison: value GREATER value
#line 567 "parser/parser.yy"
                          {
    }
#line 1816 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 121: // comparaison: value LESSER value
#line 569 "parser/parser.yy"
                         {
    }
#line 1823 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 122: // comparaison: value GREATEROREQUAL value
#line 571 "parser/parser.yy"
                                 {
    }
#line 1830 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;

  case 123: // comparaison: value LESSEROREQUAL value
#line 573 "parser/parser.yy"
                                {
    }
#line 1837 "/home/ebrio/Téléchargements/proj/build/parser.cpp"
    break;


#line 1841 "/home/ebrio/Téléchargements/proj/build/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
   Parser ::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const short  Parser ::yypact_ninf_ = -136;

  const signed char  Parser ::yytable_ninf_ = -115;

  const short
   Parser ::yypact_[] =
  {
      20,    15,  -136,  -136,     4,   -29,  -136,  -136,  -136,  -136,
     -20,    32,   -15,   103,    42,   109,   109,    52,  -136,  -136,
     138,  -136,  -136,     5,  -136,  -136,    29,  -136,   423,   172,
     163,  -136,   282,  -136,  -136,  -136,    41,  -136,   103,  -136,
    -136,   439,    70,    26,  -136,  -136,   206,  -136,   189,  -136,
     165,   247,    60,  -136,    76,    85,    89,    95,    96,   102,
     362,   109,   109,   109,   109,  -136,    16,   100,  -136,  -136,
     444,  -136,    17,   -21,   -13,   444,  -136,    -8,   106,   111,
     113,   118,  -136,  -136,  -136,   140,    99,   143,   120,   120,
     120,   120,   120,   120,   374,   -34,  -136,  -136,  -136,  -136,
    -136,   152,   153,   157,   169,   174,     3,   146,   276,   109,
     109,   109,   109,   109,   109,   109,  -136,   -19,   -19,  -136,
    -136,   194,   180,  -136,   109,   183,  -136,  -136,   171,   184,
     187,   190,   175,   193,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,    19,    99,    99,   148,   160,   176,   234,   273,   444,
     444,   247,   196,   314,   350,   366,   392,   400,   408,    43,
    -136,  -136,   416,  -136,   252,   254,   256,   269,   260,    99,
     219,   285,   222,   231,   261,   272,   279,   281,  -136,  -136,
    -136,  -136,   235,   238,  -136,  -136,  -136,   462,   255,   259,
     266,   267,   268,   270,  -136,   248,   257,   275,   277,   444,
     278,   283,   374,  -136,   226,   263,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,   253,   316,   319,
     462,   462,   462,   462,  -136,  -136,  -136,  -136,   291,  -136,
      99,   311,   300,   304,   337,   300,   306,    93,   292,   295,
     298,   307,   310,   312,  -136,   297,   365,  -136,   329,  -136,
     300,  -136,   330,  -136,  -136,   325,   377,   382,   384,   386,
     385,  -136,  -136,  -136,  -136,  -136,   444,  -136,  -136,   359,
     344,  -136,   340,  -136,  -136,  -136
  };

  const signed char
   Parser ::yydefact_[] =
  {
       0,     0,     5,   107,   108,     0,    70,    71,    72,    26,
       0,     0,     0,     0,     0,     0,     0,     0,    19,    18,
       0,    24,    25,     0,    20,    21,    77,     4,     0,     0,
       0,    65,     0,    62,    63,    64,     0,    57,     0,   115,
     116,     0,     0,     0,   108,   114,     0,     1,     0,     3,
      32,    30,     0,    23,     0,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,    91,   100,    97,    98,    99,
       0,    92,     0,   106,   102,     0,   103,     0,     0,     0,
       0,     0,    74,    75,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,     4,     2,    29,
      27,     0,     0,     0,     0,     0,    61,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,   111,   110,   112,
     113,     0,     0,    93,     0,     0,   104,   105,     0,     0,
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
      94,    96,     0,   101,     0,     0,     0,     0,     0,     0,
       0,     9,     0,     0,    48,    40,    50,    42,    54,    46,
      55,    47,    52,    44,    59,    58,    22,     0,     0,     0,
       0,     0,     0,     0,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     0,    49,    41,    51,    43,
      53,    45,    35,    36,    38,    39,    37,     0,     0,     0,
       0,     0,     0,     0,    66,    67,    68,    69,     0,    33,
       0,     0,    13,     0,    12,    13,     0,     0,     0,     0,
       0,     0,     0,     0,    34,     0,     6,    13,     0,    17,
      13,    11,     0,    14,    88,     0,     0,     0,     0,     0,
       0,    56,     7,    15,    10,    16,     0,    81,    83,     0,
       0,    90,     0,    85,    87,    79
  };

  const short
   Parser ::yypgoto_[] =
  {
    -136,     0,  -136,  -135,  -136,     2,   -46,  -136,    -2,  -136,
     -28,   -67,   -22,  -136,   376,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,    24,   397,   367
  };

  const unsigned char
   Parser ::yydefgoto_[] =
  {
       0,    17,    18,   233,    19,   234,    53,    21,   217,   106,
      39,   107,    40,    22,    23,    85,    24,    25,    54,    55,
      56,    57,    58,    59,    26,    41,    42
  };

  const short
   Parser ::yytable_[] =
  {
      71,    76,    20,   122,    99,   100,   149,    77,   125,   -73,
       3,   -73,    50,   -62,   116,   142,   143,   -73,    51,    27,
      49,   -63,    20,     1,     2,     3,   126,     4,     5,   -73,
     123,     6,    63,    64,     7,    29,     8,    30,   -62,    45,
      46,     9,    32,    10,    11,    31,   -63,    60,    98,    43,
      20,   127,    47,   -73,    15,    12,    13,   170,   171,   -73,
      52,   -73,    16,   150,   133,     3,    14,    44,    28,    15,
     236,   -73,   124,    95,    60,    60,   108,    16,    61,    62,
      63,    64,   184,   185,    60,   117,   118,   119,   120,   101,
     102,   103,   104,   105,  -114,  -114,   141,   248,    86,   251,
     252,   200,    36,    37,    33,   186,    34,    35,    33,    15,
      34,    35,    36,    37,     3,   264,    44,    16,   179,   181,
     172,   173,   175,   177,    94,    33,   183,    34,    35,    36,
      37,   109,   228,   153,   154,   155,   156,   157,   158,   159,
     110,    48,     2,     3,   111,     4,     5,   201,   162,     6,
     112,   113,     7,    33,     8,   174,    35,   114,    15,     9,
      38,    10,    11,   121,   128,    33,    16,   176,    35,   129,
       3,   130,    50,    12,    13,    60,   131,    73,    51,    74,
      35,    36,    37,   178,    14,    36,    37,    15,    78,    79,
      80,    81,     1,    97,     3,    16,     4,     5,   132,   272,
       6,   134,   151,     7,   231,     8,   144,   145,   245,   254,
       9,   146,    10,    11,    15,  -108,  -108,  -108,   240,   241,
     242,   243,    16,   147,    12,    13,   160,    75,   148,   232,
     168,     3,   164,     4,     5,    14,   161,     6,    15,   163,
       7,   180,     8,    36,    37,   165,    16,     9,   166,    10,
      11,   167,     3,   169,    50,    61,    62,    63,    64,   187,
      51,    12,    13,   199,    96,   195,   235,   196,     3,   197,
       4,     5,    14,   202,     6,    15,   204,     7,    33,     8,
     182,    35,   198,    16,     9,   205,    10,    11,   203,   101,
     102,   103,   104,   105,   210,   206,    15,   211,    12,    13,
      82,    83,    84,   247,    16,     3,   207,     4,     5,    14,
     224,     6,    15,   208,     7,   209,     8,   237,   218,   225,
      16,     9,   219,    10,    11,    61,    62,    63,    64,   220,
     221,   222,   152,   223,   229,    12,    13,   226,   238,   227,
     250,   239,     3,   230,     4,     5,    14,   244,     6,    15,
     246,     7,   249,     8,   253,   261,   255,    16,     9,   256,
      10,    11,   257,    61,    62,    63,    64,     3,   262,    50,
     188,   258,    12,    13,   259,    51,   260,   263,   265,     3,
     266,     4,     5,    14,   267,     6,    15,   268,     7,   269,
       8,   270,   271,   273,    16,     9,   275,    10,    11,    61,
      62,    63,    64,   274,    72,    87,   189,     0,     0,    12,
      13,   115,    62,    63,    64,    61,    62,    63,    64,    16,
      14,     0,   190,    15,     0,     0,     0,     0,    65,     0,
      66,    16,    36,    37,     6,    67,     0,     7,    68,     8,
      69,    61,    62,    63,    64,     0,     0,     0,   191,    61,
      62,    63,    64,     0,     0,     0,   192,    61,    62,    63,
      64,     0,     0,     0,   193,    61,    62,    63,    64,     0,
       0,     0,   194,   101,   102,   103,   104,   105,    70,    88,
      89,    90,    91,    92,    93,   135,   136,   137,   138,   139,
     140,   212,   213,   214,   215,   216
  };

  const short
   Parser ::yycheck_[] =
  {
      28,    29,     0,    70,    50,    51,     3,    29,    75,     5,
       5,     7,     7,    34,    60,    49,    50,    13,    13,     4,
      20,    34,    20,     3,     4,     5,    34,     7,     8,    13,
      13,    11,    51,    52,    14,    64,    16,    57,    59,    15,
      16,    21,    57,    23,    24,    13,    59,    23,    48,     7,
      48,    59,     0,    49,    49,    35,    36,    38,    39,    55,
      55,    57,    57,    60,    86,     5,    46,     7,    64,    49,
     205,    55,    55,    47,    50,    51,    52,    57,    49,    50,
      51,    52,   149,   150,    60,    61,    62,    63,    64,    29,
      30,    31,    32,    33,    51,    52,    94,   232,    57,   234,
     235,   168,     9,    10,     5,   151,     7,     8,     5,    49,
       7,     8,     9,    10,     5,   250,     7,    57,   146,   147,
     142,   143,   144,   145,    54,     5,   148,     7,     8,     9,
      10,    55,   199,   109,   110,   111,   112,   113,   114,   115,
      55,     3,     4,     5,    55,     7,     8,   169,   124,    11,
      55,    55,    14,     5,    16,     7,     8,    55,    49,    21,
      57,    23,    24,    63,    58,     5,    57,     7,     8,    58,
       5,    58,     7,    35,    36,   151,    58,     5,    13,     7,
       8,     9,    10,     7,    46,     9,    10,    49,    25,    26,
      27,    28,     3,     4,     5,    57,     7,     8,    58,   266,
      11,    58,    56,    14,   202,    16,    54,    54,   230,   237,
      21,    54,    23,    24,    49,    50,    51,    52,   220,   221,
     222,   223,    57,    54,    35,    36,    32,    55,    54,     3,
      55,     5,    61,     7,     8,    46,    56,    11,    49,    56,
      14,     7,    16,     9,    10,    61,    57,    21,    61,    23,
      24,    61,     5,    60,     7,    49,    50,    51,    52,    63,
      13,    35,    36,     3,    58,    13,     3,    13,     5,    13,
       7,     8,    46,    54,    11,    49,    54,    14,     5,    16,
       7,     8,    13,    57,    21,    54,    23,    24,     3,    29,
      30,    31,    32,    33,    59,    34,    49,    59,    35,    36,
      18,    19,    20,     3,    57,     5,    34,     7,     8,    46,
      62,    11,    49,    34,    14,    34,    16,    64,    63,    62,
      57,    21,    63,    23,    24,    49,    50,    51,    52,    63,
      63,    63,    56,    63,    56,    35,    36,    62,    22,    62,
       3,    22,     5,    60,     7,     8,    46,    56,    11,    49,
      39,    14,    48,    16,    48,    58,    64,    57,    21,    64,
      23,    24,    64,    49,    50,    51,    52,     5,     3,     7,
      56,    64,    35,    36,    64,    13,    64,    48,    48,     5,
      55,     7,     8,    46,     7,    11,    49,     5,    14,     5,
      16,     5,     7,    34,    57,    21,    56,    23,    24,    49,
      50,    51,    52,    59,    28,    38,    56,    -1,    -1,    35,
      36,    49,    50,    51,    52,    49,    50,    51,    52,    57,
      46,    -1,    56,    49,    -1,    -1,    -1,    -1,     5,    -1,
       7,    57,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    49,    50,    51,    52,    -1,    -1,    -1,    56,    49,
      50,    51,    52,    -1,    -1,    -1,    56,    49,    50,    51,
      52,    -1,    -1,    -1,    56,    49,    50,    51,    52,    -1,
      -1,    -1,    56,    29,    30,    31,    32,    33,    55,    40,
      41,    42,    43,    44,    45,    88,    89,    90,    91,    92,
      93,    29,    30,    31,    32,    33
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     7,     8,    11,    14,    16,    21,
      23,    24,    35,    36,    46,    49,    57,    66,    67,    69,
      70,    72,    78,    79,    81,    82,    89,     4,    64,    64,
      57,    13,    57,     5,     7,     8,     9,    10,    57,    75,
      77,    90,    91,     7,     7,    89,    89,     0,     3,    66,
       7,    13,    55,    71,    83,    84,    85,    86,    87,    88,
      89,    49,    50,    51,    52,     5,     7,    12,    15,    17,
      55,    75,    79,     5,     7,    55,    75,    77,    25,    26,
      27,    28,    18,    19,    20,    80,    57,    91,    40,    41,
      42,    43,    44,    45,    54,    47,    58,     4,    66,    71,
      71,    29,    30,    31,    32,    33,    74,    76,    89,    55,
      55,    55,    55,    55,    55,    49,    71,    89,    89,    89,
      89,    63,    76,    13,    55,    76,    34,    59,    58,    58,
      58,    58,    58,    77,    58,    90,    90,    90,    90,    90,
      90,    70,    49,    50,    54,    54,    54,    54,    54,     3,
      60,    56,    56,    89,    89,    89,    89,    89,    89,    89,
      32,    56,    89,    56,    61,    61,    61,    61,    55,    60,
      38,    39,    77,    77,     7,    77,     7,    77,     7,    75,
       7,    75,     7,    77,    76,    76,    71,    63,    56,    56,
      56,    56,    56,    56,    56,    13,    13,    13,    13,     3,
      76,    77,    54,     3,    54,    54,    34,    34,    34,    34,
      59,    59,    29,    30,    31,    32,    33,    73,    63,    63,
      63,    63,    63,    63,    62,    62,    62,    62,    76,    56,
      60,    70,     3,    68,    70,     3,    68,    64,    22,    22,
      73,    73,    73,    73,    56,    77,    39,     3,    68,    48,
       3,    68,    68,    48,    75,    64,    64,    64,    64,    64,
      64,    58,     3,    48,    68,    48,    55,     7,     5,     5,
       5,     7,    76,    34,    59,    56
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    65,    66,    66,    66,    66,    67,    67,    67,    67,
      68,    68,    68,    68,    69,    69,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    71,
      71,    71,    71,    72,    72,    73,    73,    73,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    75,    75,    76,    76,
      76,    76,    77,    77,    77,    78,    78,    78,    78,    78,
      79,    79,    79,    79,    80,    80,    80,    81,    83,    82,
      84,    82,    85,    82,    86,    82,    87,    82,    82,    88,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    89,    89,    89,
      89,    89,    89,    89,    89,    90,    90,    91,    91,    91,
      91,    91,    91,    91
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     3,     2,     2,     1,     8,     9,     6,     5,
       3,     2,     1,     1,     8,     9,     9,     8,     1,     1,
       1,     1,     5,     2,     1,     1,     1,     2,     2,     2,
       1,     1,     1,     7,     8,     1,     1,     1,     1,     1,
       3,     4,     3,     4,     3,     4,     3,     3,     3,     4,
       3,     4,     3,     4,     3,     3,     8,     1,     3,     3,
       2,     1,     1,     1,     1,     2,     7,     7,     7,     7,
       1,     1,     1,     1,     1,     1,     1,     1,     0,    11,
       0,     9,     0,     9,     0,    10,     0,    10,     8,     0,
       9,     3,     3,     4,     5,     6,     5,     3,     3,     3,
       3,     5,     3,     3,     4,     4,     3,     1,     1,     3,
       3,     3,     3,     3,     2,     1,     1,     3,     3,     3,
       3,     3,     3,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "NL", "END", "NUMBER",
  "HEXANUMBER", "VAR", "VARATTRIBUT", "COULEUR", "COULEURHEXA", "TITLE",
  "TITLEID", "TEXT", "IMAGE", "IMAGEID", "PARAGRAPH", "PARAGRAPHID",
  "UNIVPAGE", "UNIVTITLE", "UNIVPARAGRAPH", "COMMENTAIRE", "STYLESELEC",
  "DEFINE", "TITREPAGE", "ENCODAGE", "ICONE", "CSS", "LANGUE", "LARGEUR",
  "HAUTEUR", "COULEURTEXTE", "COULEURFOND", "OPACITE", "PIXEL", "STYLE",
  "SI", "ALORS", "SINON", "FINSI", "EGAL", "DIFFERENT", "GREATER",
  "LESSER", "GREATEROREQUAL", "LESSEROREQUAL", "POUR", "RANGE", "FINI",
  "'-'", "'+'", "'*'", "'/'", "NEG", "':'", "'['", "']'", "'('", "')'",
  "'%'", "','", "'{'", "'}'", "'.'", "'='", "$accept", "programme", "si",
  "pourinterne", "pour", "instruction", "textebloc", "style",
  "nomattribut", "attribut", "couleur", "attributs", "number", "parametre",
  "bloc", "blocuniv", "expression", "affectation", "$@1", "$@2", "$@3",
  "$@4", "$@5", "$@6", "operation", "value", "comparaison", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   118,   118,   119,   120,   123,   128,   129,   130,   131,
     134,   135,   136,   137,   140,   142,   144,   146,   150,   151,
     152,   155,   157,   163,   167,   169,   171,   176,   179,   183,
     186,   189,   193,   198,   201,   206,   207,   208,   209,   210,
     213,   217,   221,   225,   229,   233,   237,   241,   245,   249,
     253,   257,   261,   265,   269,   274,   282,   293,   304,   309,
     314,   319,   326,   329,   332,   338,   341,   344,   347,   350,
     355,   358,   361,   364,   368,   371,   374,   379,   385,   385,
     387,   387,   389,   389,   391,   391,   393,   393,   395,   397,
     397,   399,   405,   412,   419,   423,   427,   433,   451,   460,
     469,   473,   482,   489,   500,   510,   519,   531,   534,   538,
     541,   544,   547,   550,   553,   558,   559,   562,   563,   565,
     567,   569,   571,   573
  };

  void
   Parser ::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
   Parser ::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

   Parser ::symbol_kind_type
   Parser ::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    59,     2,     2,
      57,    58,    51,    50,    60,    49,    63,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,     2,
       2,    64,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,    62,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    53
    };
    // Last valid token kind.
    const int code_max = 304;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 2423 "/home/ebrio/Téléchargements/proj/build/parser.cpp"

#line 576 "parser/parser.yy"


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
