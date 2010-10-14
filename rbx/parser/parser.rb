module Fancy

  # This module has methods that can be used as callbacks from
  # the parser, so that we can have a relatively simple fancy.y
  # For example, when the parser sees a literal (or any other node)
  # it just calls methods defined here. that create actual
  # Fancy::AST nodes, returning them to the parser to be stored on
  # $$
  module Parser

    extend self

    # For TERMINALS, like INTEGER_LITERAL, STRING_LITERAL, etc
    # we can create the nodes by manipulaing the yytext
    # For non-terminals we will see.

    def string_literal(line, yytext)
      # yytext contains the opening " and the closing "
      puts "String(#{yytext}) at line #{line}"
      str = yytext[1..-2]
      p str
      Rubinius::AST::StringLiteral.new(line, str)
    end


    def integer_literal(line, yytext)
      # yytext is an string, so we just call ruby's to_i on it.
      Rubinius::AST::FixnumLiteral.new(line, yytext.to_i)
    end

    require 'fancy_parser'

  end

end