describe "A Match2 node" do
  parse '/x/ =~ "blah"' do
    [:match2, [:regex, "x", 0], [:str, "blah"]]
  end

  parse <<-ruby do
      x = "x"
      /\#{x}/ =~ x
    ruby

    [:block,
     [:lasgn, :x, [:str, "x"]],
     [:match2, [:dregx, "", [:evstr, [:lvar, :x]]], [:lvar, :x]]]
  end
end
