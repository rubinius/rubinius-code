describe "A Not node" do
  parse "(not true)" do
    [:call, [:true], :!, [:arglist]]
  end

  parse <<-ruby do
      a = 1
      b = !a
    ruby

    [:block,
     [:lasgn, :a, [:lit, 1]],
     [:lasgn, :b, [:call, [:lvar, :a], :!, [:arglist]]]]
  end
end
