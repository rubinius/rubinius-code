describe "A Defined node" do
  parse "defined? $x" do
    [:defined, [:gvar, :$x]]
  end

  parse "defined? a" do
    [:defined, [:call, nil, :a, [:arglist]]]
  end

  parse <<-ruby do
      a = 1
      defined? a
    ruby

    [:block, [:lasgn, :a, [:lit, 1]], [:defined, [:lvar, :a]]]
  end

  parse "defined? x = 1" do
    [:defined, [:lasgn, :x, [:lit, 1]]]
  end

  parse "defined? x += 1" do
    [:defined, [:lasgn, :x, [:call, [:lvar, :x], :+, [:arglist, [:lit, 1]]]]]
  end

  parse "defined? x ||= 1" do
    [:defined, [:op_asgn_or, [:lvar, :x], [:lasgn, :x, [:lit, 1]]]]
  end

  parse "defined? x &&= 1" do
    [:defined, [:op_asgn_and, [:lvar, :x], [:lasgn, :x, [:lit, 1]]]]
  end

  parse "defined? X" do
    [:defined, [:const, :X]]
  end

  parse "defined? ::X" do
    [:defined, [:colon3, :X]]
  end

  parse "defined? X::Y" do
    [:defined, [:colon2, [:const, :X], :Y]]
  end

  parse "defined? X::Y::Z" do
    [:defined, [:colon2, [:colon2, [:const, :X], :Y], :Z]]
  end

  parse "defined? self::A" do
    [:defined, [:colon2, [:self], :A]]
  end

  parse "defined? self" do
    [:defined, [:self]]
  end

  parse "defined? true" do
    [:defined, [:true]]
  end

  parse "defined? false" do
    [:defined, [:false]]
  end

  parse "defined? nil" do
    [:defined, [:nil]]
  end

  parse "defined? @var" do
    [:defined, [:ivar, :@var]]
  end

  parse "defined? @@var" do
    [:defined, [:cvar, :@@var]]
  end

  parse "defined? :a" do
    [:defined, [:lit, :a]]
  end

  parse "defined? 'a'" do
    [:defined, [:str, "a"]]
  end

  parse "defined? 0" do
    [:defined, [:lit, 0]]
  end

  parse "defined? yield" do
    [:defined, [:yield]]
  end

  parse "defined? A.m" do
    [:defined, [:call, [:const, :A], :m, [:arglist]]]
  end

  parse "defined? ::A.m" do
    [:defined, [:call, [:colon3, :A], :m, [:arglist]]]
  end

  parse "defined? A::B.m" do
    [:defined, [:call, [:colon2, [:const, :A], :B], :m, [:arglist]]]
  end

  parse "defined? a.b" do
    [:defined, [:call, [:call, nil, :a, [:arglist]], :b, [:arglist]]]
  end

  parse <<-ruby do
      a = 1
      defined? a.to_s
    ruby

    [:block,
     [:lasgn, :a, [:lit, 1]],
     [:defined, [:call, [:lvar, :a], :to_s, [:arglist]]]]
  end
end
