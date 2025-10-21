// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file /home/ebrio/Téléchargements/proj/build/parser.hpp
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_HOME_EBRIO_T_L_CHARGEMENTS_PROJ_BUILD_PARSER_HPP_INCLUDED
# define YY_YY_HOME_EBRIO_T_L_CHARGEMENTS_PROJ_BUILD_PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 11 "parser/parser.yy"

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

#line 70 "/home/ebrio/Téléchargements/proj/build/parser.hpp"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

namespace yy {
#line 210 "/home/ebrio/Téléchargements/proj/build/parser.hpp"




  /// A Bison parser.
  class  Parser 
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // NUMBER
      // TITLE
      // number
      // operation
      char dummy1[sizeof (int)];

      // attribut
      char dummy2[sizeof (std::shared_ptr<Attribut>)];

      // bloc
      char dummy3[sizeof (std::shared_ptr<Bloc>)];

      // couleur
      char dummy4[sizeof (std::shared_ptr<Couleur>)];

      // attributs
      char dummy5[sizeof (std::shared_ptr<Style>)];

      // HEXANUMBER
      // VAR
      // VARATTRIBUT
      // COULEURHEXA
      // TITLEID
      // TEXT
      // IMAGEID
      // PARAGRAPHID
      // UNIVTITLE
      // COMMENTAIRE
      // RANGE
      // textebloc
      // blocuniv
      char dummy6[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    NL = 258,                      // NL
    END = 259,                     // END
    NUMBER = 260,                  // NUMBER
    HEXANUMBER = 261,              // HEXANUMBER
    VAR = 262,                     // VAR
    VARATTRIBUT = 263,             // VARATTRIBUT
    COULEUR = 264,                 // COULEUR
    COULEURHEXA = 265,             // COULEURHEXA
    TITLE = 266,                   // TITLE
    TITLEID = 267,                 // TITLEID
    TEXT = 268,                    // TEXT
    IMAGE = 269,                   // IMAGE
    IMAGEID = 270,                 // IMAGEID
    PARAGRAPH = 271,               // PARAGRAPH
    PARAGRAPHID = 272,             // PARAGRAPHID
    UNIVPAGE = 273,                // UNIVPAGE
    UNIVTITLE = 274,               // UNIVTITLE
    UNIVPARAGRAPH = 275,           // UNIVPARAGRAPH
    COMMENTAIRE = 276,             // COMMENTAIRE
    STYLESELEC = 277,              // STYLESELEC
    DEFINE = 278,                  // DEFINE
    TITREPAGE = 279,               // TITREPAGE
    ENCODAGE = 280,                // ENCODAGE
    ICONE = 281,                   // ICONE
    CSS = 282,                     // CSS
    LANGUE = 283,                  // LANGUE
    LARGEUR = 284,                 // LARGEUR
    HAUTEUR = 285,                 // HAUTEUR
    COULEURTEXTE = 286,            // COULEURTEXTE
    COULEURFOND = 287,             // COULEURFOND
    OPACITE = 288,                 // OPACITE
    PIXEL = 289,                   // PIXEL
    STYLE = 290,                   // STYLE
    SI = 291,                      // SI
    ALORS = 292,                   // ALORS
    SINON = 293,                   // SINON
    FINSI = 294,                   // FINSI
    EGAL = 295,                    // EGAL
    DIFFERENT = 296,               // DIFFERENT
    GREATER = 297,                 // GREATER
    LESSER = 298,                  // LESSER
    GREATEROREQUAL = 299,          // GREATEROREQUAL
    LESSEROREQUAL = 300,           // LESSEROREQUAL
    POUR = 301,                    // POUR
    RANGE = 302,                   // RANGE
    FINI = 303,                    // FINI
    NEG = 304                      // NEG
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 65, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_NL = 3,                                // NL
        S_END = 4,                               // END
        S_NUMBER = 5,                            // NUMBER
        S_HEXANUMBER = 6,                        // HEXANUMBER
        S_VAR = 7,                               // VAR
        S_VARATTRIBUT = 8,                       // VARATTRIBUT
        S_COULEUR = 9,                           // COULEUR
        S_COULEURHEXA = 10,                      // COULEURHEXA
        S_TITLE = 11,                            // TITLE
        S_TITLEID = 12,                          // TITLEID
        S_TEXT = 13,                             // TEXT
        S_IMAGE = 14,                            // IMAGE
        S_IMAGEID = 15,                          // IMAGEID
        S_PARAGRAPH = 16,                        // PARAGRAPH
        S_PARAGRAPHID = 17,                      // PARAGRAPHID
        S_UNIVPAGE = 18,                         // UNIVPAGE
        S_UNIVTITLE = 19,                        // UNIVTITLE
        S_UNIVPARAGRAPH = 20,                    // UNIVPARAGRAPH
        S_COMMENTAIRE = 21,                      // COMMENTAIRE
        S_STYLESELEC = 22,                       // STYLESELEC
        S_DEFINE = 23,                           // DEFINE
        S_TITREPAGE = 24,                        // TITREPAGE
        S_ENCODAGE = 25,                         // ENCODAGE
        S_ICONE = 26,                            // ICONE
        S_CSS = 27,                              // CSS
        S_LANGUE = 28,                           // LANGUE
        S_LARGEUR = 29,                          // LARGEUR
        S_HAUTEUR = 30,                          // HAUTEUR
        S_COULEURTEXTE = 31,                     // COULEURTEXTE
        S_COULEURFOND = 32,                      // COULEURFOND
        S_OPACITE = 33,                          // OPACITE
        S_PIXEL = 34,                            // PIXEL
        S_STYLE = 35,                            // STYLE
        S_SI = 36,                               // SI
        S_ALORS = 37,                            // ALORS
        S_SINON = 38,                            // SINON
        S_FINSI = 39,                            // FINSI
        S_EGAL = 40,                             // EGAL
        S_DIFFERENT = 41,                        // DIFFERENT
        S_GREATER = 42,                          // GREATER
        S_LESSER = 43,                           // LESSER
        S_GREATEROREQUAL = 44,                   // GREATEROREQUAL
        S_LESSEROREQUAL = 45,                    // LESSEROREQUAL
        S_POUR = 46,                             // POUR
        S_RANGE = 47,                            // RANGE
        S_FINI = 48,                             // FINI
        S_49_ = 49,                              // '-'
        S_50_ = 50,                              // '+'
        S_51_ = 51,                              // '*'
        S_52_ = 52,                              // '/'
        S_NEG = 53,                              // NEG
        S_54_ = 54,                              // ':'
        S_55_ = 55,                              // '['
        S_56_ = 56,                              // ']'
        S_57_ = 57,                              // '('
        S_58_ = 58,                              // ')'
        S_59_ = 59,                              // '%'
        S_60_ = 60,                              // ','
        S_61_ = 61,                              // '{'
        S_62_ = 62,                              // '}'
        S_63_ = 63,                              // '.'
        S_64_ = 64,                              // '='
        S_YYACCEPT = 65,                         // $accept
        S_programme = 66,                        // programme
        S_si = 67,                               // si
        S_pourinterne = 68,                      // pourinterne
        S_pour = 69,                             // pour
        S_instruction = 70,                      // instruction
        S_textebloc = 71,                        // textebloc
        S_style = 72,                            // style
        S_nomattribut = 73,                      // nomattribut
        S_attribut = 74,                         // attribut
        S_couleur = 75,                          // couleur
        S_attributs = 76,                        // attributs
        S_number = 77,                           // number
        S_parametre = 78,                        // parametre
        S_bloc = 79,                             // bloc
        S_blocuniv = 80,                         // blocuniv
        S_expression = 81,                       // expression
        S_affectation = 82,                      // affectation
        S_83_1 = 83,                             // $@1
        S_84_2 = 84,                             // $@2
        S_85_3 = 85,                             // $@3
        S_86_4 = 86,                             // $@4
        S_87_5 = 87,                             // $@5
        S_88_6 = 88,                             // $@6
        S_operation = 89,                        // operation
        S_value = 90,                            // value
        S_comparaison = 91                       // comparaison
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_TITLE: // TITLE
      case symbol_kind::S_number: // number
      case symbol_kind::S_operation: // operation
        value.move< int > (std::move (that.value));
        break;

      case symbol_kind::S_attribut: // attribut
        value.move< std::shared_ptr<Attribut> > (std::move (that.value));
        break;

      case symbol_kind::S_bloc: // bloc
        value.move< std::shared_ptr<Bloc> > (std::move (that.value));
        break;

      case symbol_kind::S_couleur: // couleur
        value.move< std::shared_ptr<Couleur> > (std::move (that.value));
        break;

      case symbol_kind::S_attributs: // attributs
        value.move< std::shared_ptr<Style> > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Attribut>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Attribut>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Bloc>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Bloc>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Couleur>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Couleur>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Style>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Style>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_TITLE: // TITLE
      case symbol_kind::S_number: // number
      case symbol_kind::S_operation: // operation
        value.template destroy< int > ();
        break;

      case symbol_kind::S_attribut: // attribut
        value.template destroy< std::shared_ptr<Attribut> > ();
        break;

      case symbol_kind::S_bloc: // bloc
        value.template destroy< std::shared_ptr<Bloc> > ();
        break;

      case symbol_kind::S_couleur: // couleur
        value.template destroy< std::shared_ptr<Couleur> > ();
        break;

      case symbol_kind::S_attributs: // attributs
        value.template destroy< std::shared_ptr<Style> > ();
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
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if YYDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return  Parser ::symbol_name (this->kind ());
      }
#endif // #if YYDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::YYEOF
                   || (token::YYerror <= tok && tok <= token::END)
                   || tok == token::COULEUR
                   || tok == token::IMAGE
                   || tok == token::PARAGRAPH
                   || tok == token::UNIVPAGE
                   || tok == token::UNIVPARAGRAPH
                   || (token::STYLESELEC <= tok && tok <= token::POUR)
                   || tok == token::FINI
                   || tok == 45
                   || tok == 43
                   || tok == 42
                   || tok == 47
                   || tok == token::NEG
                   || tok == 58
                   || tok == 91
                   || tok == 93
                   || (40 <= tok && tok <= 41)
                   || tok == 37
                   || tok == 44
                   || tok == 123
                   || tok == 125
                   || tok == 46
                   || tok == 61);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const int& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::NUMBER
                   || tok == token::TITLE);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT ((token::HEXANUMBER <= tok && tok <= token::VARATTRIBUT)
                   || tok == token::COULEURHEXA
                   || (token::TITLEID <= tok && tok <= token::TEXT)
                   || tok == token::IMAGEID
                   || tok == token::PARAGRAPHID
                   || tok == token::UNIVTITLE
                   || tok == token::COMMENTAIRE
                   || tok == token::RANGE);
#endif
      }
    };

    /// Build a parser object.
     Parser  (Scanner &scanner_yyarg, Driver &driver_yyarg, Programme &programme_yyarg);
    virtual ~ Parser  ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
     Parser  (const  Parser &) = delete;
    /// Non copyable.
     Parser & operator= (const  Parser &) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if YYDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if YYDEBUG || 0


    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NL (location_type l)
      {
        return symbol_type (token::NL, std::move (l));
      }
#else
      static
      symbol_type
      make_NL (const location_type& l)
      {
        return symbol_type (token::NL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBER (int v, location_type l)
      {
        return symbol_type (token::NUMBER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMBER (const int& v, const location_type& l)
      {
        return symbol_type (token::NUMBER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HEXANUMBER (std::string v, location_type l)
      {
        return symbol_type (token::HEXANUMBER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_HEXANUMBER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::HEXANUMBER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR (std::string v, location_type l)
      {
        return symbol_type (token::VAR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VAR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::VAR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VARATTRIBUT (std::string v, location_type l)
      {
        return symbol_type (token::VARATTRIBUT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VARATTRIBUT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::VARATTRIBUT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COULEUR (location_type l)
      {
        return symbol_type (token::COULEUR, std::move (l));
      }
#else
      static
      symbol_type
      make_COULEUR (const location_type& l)
      {
        return symbol_type (token::COULEUR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COULEURHEXA (std::string v, location_type l)
      {
        return symbol_type (token::COULEURHEXA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COULEURHEXA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::COULEURHEXA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TITLE (int v, location_type l)
      {
        return symbol_type (token::TITLE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TITLE (const int& v, const location_type& l)
      {
        return symbol_type (token::TITLE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TITLEID (std::string v, location_type l)
      {
        return symbol_type (token::TITLEID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TITLEID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TITLEID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TEXT (std::string v, location_type l)
      {
        return symbol_type (token::TEXT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TEXT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TEXT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IMAGE (location_type l)
      {
        return symbol_type (token::IMAGE, std::move (l));
      }
#else
      static
      symbol_type
      make_IMAGE (const location_type& l)
      {
        return symbol_type (token::IMAGE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IMAGEID (std::string v, location_type l)
      {
        return symbol_type (token::IMAGEID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IMAGEID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::IMAGEID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PARAGRAPH (location_type l)
      {
        return symbol_type (token::PARAGRAPH, std::move (l));
      }
#else
      static
      symbol_type
      make_PARAGRAPH (const location_type& l)
      {
        return symbol_type (token::PARAGRAPH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PARAGRAPHID (std::string v, location_type l)
      {
        return symbol_type (token::PARAGRAPHID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PARAGRAPHID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::PARAGRAPHID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNIVPAGE (location_type l)
      {
        return symbol_type (token::UNIVPAGE, std::move (l));
      }
#else
      static
      symbol_type
      make_UNIVPAGE (const location_type& l)
      {
        return symbol_type (token::UNIVPAGE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNIVTITLE (std::string v, location_type l)
      {
        return symbol_type (token::UNIVTITLE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_UNIVTITLE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::UNIVTITLE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNIVPARAGRAPH (location_type l)
      {
        return symbol_type (token::UNIVPARAGRAPH, std::move (l));
      }
#else
      static
      symbol_type
      make_UNIVPARAGRAPH (const location_type& l)
      {
        return symbol_type (token::UNIVPARAGRAPH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMENTAIRE (std::string v, location_type l)
      {
        return symbol_type (token::COMMENTAIRE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COMMENTAIRE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::COMMENTAIRE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STYLESELEC (location_type l)
      {
        return symbol_type (token::STYLESELEC, std::move (l));
      }
#else
      static
      symbol_type
      make_STYLESELEC (const location_type& l)
      {
        return symbol_type (token::STYLESELEC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEFINE (location_type l)
      {
        return symbol_type (token::DEFINE, std::move (l));
      }
#else
      static
      symbol_type
      make_DEFINE (const location_type& l)
      {
        return symbol_type (token::DEFINE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TITREPAGE (location_type l)
      {
        return symbol_type (token::TITREPAGE, std::move (l));
      }
#else
      static
      symbol_type
      make_TITREPAGE (const location_type& l)
      {
        return symbol_type (token::TITREPAGE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENCODAGE (location_type l)
      {
        return symbol_type (token::ENCODAGE, std::move (l));
      }
#else
      static
      symbol_type
      make_ENCODAGE (const location_type& l)
      {
        return symbol_type (token::ENCODAGE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ICONE (location_type l)
      {
        return symbol_type (token::ICONE, std::move (l));
      }
#else
      static
      symbol_type
      make_ICONE (const location_type& l)
      {
        return symbol_type (token::ICONE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CSS (location_type l)
      {
        return symbol_type (token::CSS, std::move (l));
      }
#else
      static
      symbol_type
      make_CSS (const location_type& l)
      {
        return symbol_type (token::CSS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LANGUE (location_type l)
      {
        return symbol_type (token::LANGUE, std::move (l));
      }
#else
      static
      symbol_type
      make_LANGUE (const location_type& l)
      {
        return symbol_type (token::LANGUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LARGEUR (location_type l)
      {
        return symbol_type (token::LARGEUR, std::move (l));
      }
#else
      static
      symbol_type
      make_LARGEUR (const location_type& l)
      {
        return symbol_type (token::LARGEUR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HAUTEUR (location_type l)
      {
        return symbol_type (token::HAUTEUR, std::move (l));
      }
#else
      static
      symbol_type
      make_HAUTEUR (const location_type& l)
      {
        return symbol_type (token::HAUTEUR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COULEURTEXTE (location_type l)
      {
        return symbol_type (token::COULEURTEXTE, std::move (l));
      }
#else
      static
      symbol_type
      make_COULEURTEXTE (const location_type& l)
      {
        return symbol_type (token::COULEURTEXTE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COULEURFOND (location_type l)
      {
        return symbol_type (token::COULEURFOND, std::move (l));
      }
#else
      static
      symbol_type
      make_COULEURFOND (const location_type& l)
      {
        return symbol_type (token::COULEURFOND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPACITE (location_type l)
      {
        return symbol_type (token::OPACITE, std::move (l));
      }
#else
      static
      symbol_type
      make_OPACITE (const location_type& l)
      {
        return symbol_type (token::OPACITE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PIXEL (location_type l)
      {
        return symbol_type (token::PIXEL, std::move (l));
      }
#else
      static
      symbol_type
      make_PIXEL (const location_type& l)
      {
        return symbol_type (token::PIXEL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STYLE (location_type l)
      {
        return symbol_type (token::STYLE, std::move (l));
      }
#else
      static
      symbol_type
      make_STYLE (const location_type& l)
      {
        return symbol_type (token::STYLE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SI (location_type l)
      {
        return symbol_type (token::SI, std::move (l));
      }
#else
      static
      symbol_type
      make_SI (const location_type& l)
      {
        return symbol_type (token::SI, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ALORS (location_type l)
      {
        return symbol_type (token::ALORS, std::move (l));
      }
#else
      static
      symbol_type
      make_ALORS (const location_type& l)
      {
        return symbol_type (token::ALORS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SINON (location_type l)
      {
        return symbol_type (token::SINON, std::move (l));
      }
#else
      static
      symbol_type
      make_SINON (const location_type& l)
      {
        return symbol_type (token::SINON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FINSI (location_type l)
      {
        return symbol_type (token::FINSI, std::move (l));
      }
#else
      static
      symbol_type
      make_FINSI (const location_type& l)
      {
        return symbol_type (token::FINSI, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EGAL (location_type l)
      {
        return symbol_type (token::EGAL, std::move (l));
      }
#else
      static
      symbol_type
      make_EGAL (const location_type& l)
      {
        return symbol_type (token::EGAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIFFERENT (location_type l)
      {
        return symbol_type (token::DIFFERENT, std::move (l));
      }
#else
      static
      symbol_type
      make_DIFFERENT (const location_type& l)
      {
        return symbol_type (token::DIFFERENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER (location_type l)
      {
        return symbol_type (token::GREATER, std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER (const location_type& l)
      {
        return symbol_type (token::GREATER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESSER (location_type l)
      {
        return symbol_type (token::LESSER, std::move (l));
      }
#else
      static
      symbol_type
      make_LESSER (const location_type& l)
      {
        return symbol_type (token::LESSER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATEROREQUAL (location_type l)
      {
        return symbol_type (token::GREATEROREQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_GREATEROREQUAL (const location_type& l)
      {
        return symbol_type (token::GREATEROREQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESSEROREQUAL (location_type l)
      {
        return symbol_type (token::LESSEROREQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_LESSEROREQUAL (const location_type& l)
      {
        return symbol_type (token::LESSEROREQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POUR (location_type l)
      {
        return symbol_type (token::POUR, std::move (l));
      }
#else
      static
      symbol_type
      make_POUR (const location_type& l)
      {
        return symbol_type (token::POUR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RANGE (std::string v, location_type l)
      {
        return symbol_type (token::RANGE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RANGE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RANGE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FINI (location_type l)
      {
        return symbol_type (token::FINI, std::move (l));
      }
#else
      static
      symbol_type
      make_FINI (const location_type& l)
      {
        return symbol_type (token::FINI, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEG (location_type l)
      {
        return symbol_type (token::NEG, std::move (l));
      }
#else
      static
      symbol_type
      make_NEG (const location_type& l)
      {
        return symbol_type (token::NEG, l);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
     Parser  (const  Parser &);
    /// Non copyable.
     Parser & operator= (const  Parser &);
#endif


    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const short yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

#if YYDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if YYDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const unsigned char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 495,     ///< Last index in yytable_.
      yynnts_ = 27,  ///< Number of nonterminal symbols.
      yyfinal_ = 47 ///< Termination state number.
    };


    // User arguments.
    Scanner &scanner;
    Driver &driver;
    Programme &programme;

  };


} // yy
#line 2193 "/home/ebrio/Téléchargements/proj/build/parser.hpp"




#endif // !YY_YY_HOME_EBRIO_T_L_CHARGEMENTS_PROJ_BUILD_PARSER_HPP_INCLUDED
