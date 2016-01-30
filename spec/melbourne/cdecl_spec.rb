describe "A Cdecl node" do
  parse "X = 42" do
    [:cdecl, :X, [:lit, 42]]
  end

  parse "::X = 1" do
    [:cdecl, [:colon3, :X], [:lit, 1]]
  end

  parse "X::Y = 1" do
    [:cdecl, [:colon2, [:const, :X], :Y], [:lit, 1]]
  end

  parse "X::Y::Z = a" do
    [:cdecl,
     [:colon2, [:colon2, [:const, :X], :Y], :Z],
     [:call, nil, :a, [:arglist]]]
  end

  parse "a::A = 1" do
    [:cdecl, [:colon2, [:call, nil, :a, [:arglist]], :A], [:lit, 1]]
  end

  parse <<-ruby do
      a = Object
      a::B = b
    ruby

    [:block,
     [:lasgn, :a, [:const, :Object]],
     [:cdecl, [:colon2, [:lvar, :a], :B], [:call, nil, :b, [:arglist]]]]
  end

  parse "X::Y ||= 1" do
    [:cdecl,
     [:colon2, [:const, :X], :Y],
     [:or, [:colon2, [:const, :X], :Y], [:lit, 1]]]
  end

  parse "X::Y &&= 1" do
    [:cdecl,
     [:colon2, [:const, :X], :Y],
     [:and, [:colon2, [:const, :X], :Y], [:lit, 1]]]
  end

  parse "X::Y += 1" do
    [:cdecl,
     [:colon2, [:const, :X], :Y],
     [:call, [:colon2, [:const, :X], :Y], :+, [:arglist, [:lit, 1]]]]
  end
end
