describe "A Regex node" do
  parse "str.split(//i)" do
    [:call,
      [:call, nil, :str, [:arglist]],
      :split,
      [:arglist, [:regex, "", 1]]]
  end

  parse "/x/n" do
    [:regex, "x", 512]
  end

  parse "/x/o" do
    [:regex, "x", 0]
  end

  parse "/x/" do
    [:regex, "x", 0]
  end
end
