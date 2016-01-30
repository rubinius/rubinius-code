describe "A Dsym node" do
  parse ':"x#{(1 + 1)}y"' do
    [:dsym,
     "x",
     [:evstr, [:call, [:lit, 1], :+, [:arglist, [:lit, 1]]]],
     [:str, "y"]]
  end
end
