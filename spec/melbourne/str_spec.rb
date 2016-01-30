describe "A Str node" do
  parse '"x"' do
    [:str, "x"]
  end

  parse <<-ruby do
      "before" \
      " after"
    ruby

    [:str, "before after"]
  end

  parse '"before" " after"' do
    [:str, "before after"]
  end

  parse <<-ruby do
      "file = \#{__FILE__}\n"
    ruby

    [:dstr, "file = ", [:evstr, [:file]], [:str, "\n"]]
  end

  parse <<-ruby do
<<'EOM'.strip
  blah
blah
EOM
    ruby

    [:call, [:str, "  blah\nblah\n"], :strip, [:arglist]]
  end

  parse <<-ruby do
a += <<-H1 + b + <<-H2
  first
H1
  second
H2
    ruby

    [:lasgn,
     :a,
     [:call,
      [:lvar, :a],
      :+,
      [:arglist,
       [:call,
        [:call, [:str, "  first\n"], :+, [:arglist, [:call, nil, :b, [:arglist]]]],
        :+,
        [:arglist, [:str, "  second\n"]]]]]]
  end

  parse <<-ruby do
<<-EOM
  blah
blah

  EOM
    ruby

    [:str, "  blah\nblah\n\n"]
  end

  parse <<-ruby do
<<'EOM'
  blah
blah
EOM
    ruby

    [:str, "  blah\nblah\n"]
  end

  parse "%(blah)" do
    [:str, "blah"]
  end
end
