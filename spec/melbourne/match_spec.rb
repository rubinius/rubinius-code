describe "A Match node" do
  parse "1 if /x/" do
    [:if, [:match, [:regex, "x", 0]], [:lit, 1], nil]
  end
end
