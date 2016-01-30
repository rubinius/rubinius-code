describe "A Hash node" do
  parse "{ 1 => 2, 3 => 4 }" do
    [:hash, [:lit, 1], [:lit, 2], [:lit, 3], [:lit, 4]]
  end

  parse "{ 1 => (2 rescue 3) }" do
    [:hash,
     [:lit, 1],
     [:rescue,
      [:lit, 2],
      [:resbody, [:array, [:const, :StandardError]], [:lit, 3]]]]
  end

  parse "{ 1 => [*1] }" do
    [:hash, [:lit, 1], [:splat, [:lit, 1]]]
  end

  parse <<-ruby do
      a = 1
      { :a => a }
    ruby

    [:block,
      [:lasgn, :a, [:lit, 1]],
      [:hash, [:lit, :a], [:lvar, :a]]]
  end

  parse <<-ruby do
      { **{ a: 1, b: 2 }, b: 2 }
    ruby

    [:hash,
     [:hash_splat],
     [:hash, [:lit, :a], [:lit, 1], [:lit, :b], [:lit, 2]],
     [:lit, :b],
     [:lit, 2]]
  end

  parse <<-ruby do
      { a: 1, **{ b: 2 }, c: 3 }
    ruby

    [:hash,
     [:lit, :a],
     [:lit, 1],
     [:hash_splat],
     [:hash, [:lit, :b], [:lit, 2]],
     [:lit, :c],
     [:lit, 3]]
  end

  parse <<-ruby do
      h = { a: 1 }
      { b: 2, **h }
    ruby

    [:block,
     [:lasgn, :h, [:hash, [:lit, :a], [:lit, 1]]],
     [:hash, [:lit, :b], [:lit, 2], [:hash_splat], [:lvar, :h]]]
  end

  parse <<-ruby do
      { a: 1, **h, c: 3 }
    ruby

    [:hash,
     [:lit, :a],
     [:lit, 1],
     [:hash_splat],
     [:call, nil, :h, [:arglist]],
     [:lit, :c],
     [:lit, 3]]
  end
end
