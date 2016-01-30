describe "A Match3 node" do
  parse '"blah" =~ /x/' do
    [:match3, [:regex, "x", 0], [:str, "blah"]]
  end

  parse <<-ruby do
      a = 'abc'
      if a =~ /\#{a}/
        1
      end
    ruby

    [:block,
     [:lasgn, :a, [:str, "abc"]],
     [:if,
      [:match3, [:dregx, "", [:evstr, [:lvar, :a]]], [:lvar, :a]],
      [:lit, 1],
      nil]]
  end
end
