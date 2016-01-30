describe "An Array node" do
  parse '[1, :b, "c"]' do
    [:array, [:lit, 1], [:lit, :b], [:str, "c"]]
  end

  parse "%w[a b c]" do
    [:array, [:str, "a"], [:str, "b"], [:str, "c"]]
  end

  parse '%w[a #{@b} c]' do
    [:array, [:str, "a"], [:str, "\#{@b}"], [:str, "c"]]
  end

  parse "%W[a b c]" do
    [:array,
      [:str, "a"], [:str, "b"], [:str, "c"]]
  end

  parse '%W[a #{@b} c]' do
    [:array,
      [:str, "a"],
      [:dstr, "", [:evstr, [:ivar, :@b]]],
      [:str, "c"]]
  end

  parse "%i[a b c]" do
    [:array, [:lit, :a], [:lit, :b], [:lit, :c]]
  end

  parse '%i[a #{@b} c]' do
    [:array, [:lit, :a], [:lit, :"\#{@b}"], [:lit, :c]]
  end

  parse "%I[a b c]" do
    [:array,
      [:dsym, "a"], [:dsym, "b"], [:dsym, "c"]]
  end

  parse '%I[a #{@b} c]' do
    [:array,
      [:dsym, "a"],
      [:dsym, "", [:evstr, [:ivar, :@b]]],
      [:dsym, "c"]]
  end

  parse "[*[1]]" do
    [:splat, [:array, [:lit, 1]]]
  end

  parse "[*1]" do
    [:splat, [:lit, 1]]
  end

  parse "[[*1]]" do
    [:array, [:splat, [:lit, 1]]]
  end

  parse "[1, *2]" do
    [:argscat, [:array, [:lit, 1]], [:lit, 2]]
  end

  parse "[1, *c()]" do
    [:argscat, [:array, [:lit, 1]], [:call, nil, :c, [:arglist]]]
  end

  parse <<-ruby do
      x = [2]
      [1, *x]
    ruby

    [:block,
     [:lasgn, :x, [:array, [:lit, 2]]],
     [:argscat, [:array, [:lit, 1]], [:lvar, :x]]]
  end
end
