describe "A Iasgn node" do
  parse "@a = 4" do
    [:iasgn, :@a, [:lit, 4]]
  end

  parse "@a = *[1]" do
    [:iasgn, :@a, [:splat, [:array, [:lit, 1]]]]
  end

  parse <<-ruby do
      a = 1
      @a = a
    ruby

    [:block,
      [:lasgn, :a, [:lit, 1]],
      [:iasgn, :@a, [:lvar, :a]]]
  end
end
