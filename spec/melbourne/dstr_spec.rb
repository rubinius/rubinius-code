describe "A Dstr node" do
  parse <<-ruby do
      "hello \#{}"
    ruby

    [:dstr, "hello ", [:evstr, [:nil]]]
  end

  parse <<-ruby do
      argl = 1
      "x\#{argl}y"
    ruby

    [:block,
     [:lasgn, :argl, [:lit, 1]],
     [:dstr, "x", [:evstr, [:lvar, :argl]], [:str, "y"]]]
  end

  parse <<-ruby do
      argl = 1
      "x\#{("%.2f" % 3.14159)}y"
    ruby

    [:block,
     [:lasgn, :argl, [:lit, 1]],
     [:dstr,
      "x",
      [:evstr, [:call, [:str, "%.2f"], :%, [:arglist, [:lit, 3.14159]]]],
      [:str, "y"]]]
  end

  parse <<-ruby do
      max = 2
      argl = 1
      "x\#{("%.\#{max}f" % 3.14159)}y"
    ruby

    [:block,
     [:lasgn, :max, [:lit, 2]],
     [:lasgn, :argl, [:lit, 1]],
     [:dstr,
      "x",
      [:evstr,
       [:call,
        [:dstr, "%.", [:evstr, [:lvar, :max]], [:str, "f"]],
        :%,
        [:arglist, [:lit, 3.14159]]]],
      [:str, "y"]]]
  end

  parse '"#{22}aa" "cd#{44}" "55" "#{66}"' do
    [:dstr,
     "",
     [:evstr, [:lit, 22]],
     [:str, "aacd"],
     [:evstr, [:lit, 44]],
     [:str, "55"],
     [:evstr, [:lit, 66]]]
  end

  parse '"a #$global b #@ivar c #@@cvar d"' do
    [:dstr,
     "a ",
     [:evstr, [:gvar, :$global]],
     [:str, " b "],
     [:evstr, [:ivar, :@ivar]],
     [:str, " c "],
     [:evstr, [:cvar, :@@cvar]],
     [:str, " d"]]
  end

  parse <<-ruby do
<<EOM
  blah
\#{1 + 1}blah
EOM
    ruby

    [:dstr,
     "  blah\n",
     [:evstr, [:call, [:lit, 1], :+, [:arglist, [:lit, 1]]]],
     [:str, "blah\n"]]
  end

  parse <<-ruby do
<<-EOF
def test_\#{action}_valid_feed
EOF
    ruby

    [:dstr,
     "def test_",
     [:evstr, [:call, nil, :action, [:arglist]]],
     [:str, "_valid_feed\n"]]
  end

  parse <<-ruby do
<<-EOF
s1 '\#{RUBY_PLATFORM}' s2
\#{__FILE__}
EOF
    ruby

    [:dstr,
     "s1 '",
     [:evstr, [:const, :RUBY_PLATFORM]],
     [:str, "' s2\n"],
     [:evstr, [:file]],
     [:str, "\n"]]
  end

  parse "%Q[before [\#{nest}] after]" do
    [:dstr,
     "before [",
     [:evstr, [:call, nil, :nest, [:arglist]]],
     [:str, "] after"]]
  end

  parse '"#{"blah"}#{__FILE__}:#{__LINE__}: warning: #{$!.message} (#{$!.class})"' do
    [:dstr,
     "blah",
     [:evstr, [:file]],
     [:str, ":"],
     [:evstr, [:lit, 1]],
     [:str, ": warning: "],
     [:evstr, [:call, [:gvar, :$!], :message, [:arglist]]],
     [:str, " ("],
     [:evstr, [:call, [:gvar, :$!], :class, [:arglist]]],
     [:str, ")"]]
  end

  parse '"before #{from} middle #{to} (#{__FILE__}:#{__LINE__})"' do
    [:dstr,
     "before ",
     [:evstr, [:call, nil, :from, [:arglist]]],
     [:str, " middle "],
     [:evstr, [:call, nil, :to, [:arglist]]],
     [:str, " ("],
     [:evstr, [:file]],
     [:str, ":"],
     [:evstr, [:lit, 1]],
     [:str, ")"]]
  end
end
