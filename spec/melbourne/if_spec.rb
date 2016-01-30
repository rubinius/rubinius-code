describe "An If node" do
  parse <<-ruby do
      if true then
        10
      else
        12
      end
    ruby

    [:if, [:true], [:lit, 10], [:lit, 12]]
  end

  parse "if b then a end" do
    [:if, [:call, nil, :b, [:arglist]], [:call, nil, :a, [:arglist]], nil]
  end

  parse <<-ruby do
      if (x = 5
      (x + 1)) then
        nil
      end
    ruby

    [:if,
     [:block,
      [:lasgn, :x, [:lit, 5]],
      [:call, [:lvar, :x], :+, [:arglist, [:lit, 1]]]],
     [:nil],
     nil]
  end

  parse <<-ruby do
      if x = obj.x then
        x.do_it
      end
    ruby

    [:if,
     [:lasgn, :x, [:call, [:call, nil, :obj, [:arglist]], :x, [:arglist]]],
     [:call, [:lvar, :x], :do_it, [:arglist]],
     nil]
  end

  parse "return if false unless true" do
    [:if, [:true], [:nil], [:if, [:false], [:return], nil]]
  end

  parse "a if not b" do
    [:if,
     [:call, [:call, nil, :b, [:arglist]], :!, [:arglist]],
     [:call, nil, :a, [:arglist]],
     nil]
  end

  parse "a if b" do
    [:if, [:call, nil, :b, [:arglist]], [:call, nil, :a, [:arglist]], nil]
  end

  parse "if not b then a end" do
    [:if,
     [:call, [:call, nil, :b, [:arglist]], :!, [:arglist]],
     [:call, nil, :a, [:arglist]],
     nil]
  end

  parse "if b then a end" do
    [:if, [:call, nil, :b, [:arglist]], [:call, nil, :a, [:arglist]], nil]
  end

  nil_condition_sexp = [:if, [:nil], [:call, nil, :a, [:arglist]], nil]

  parse "a if ()" do
    nil_condition_sexp
  end

  parse "if () then a end" do
    nil_condition_sexp
  end

  parse "a unless not b" do
    [:if,
     [:call, [:call, nil, :b, [:arglist]], :!, [:arglist]],
     [:nil],
     [:call, nil, :a, [:arglist]]]
  end

  parse "a unless b" do
    [:if, [:call, nil, :b, [:arglist]], [:nil], [:call, nil, :a, [:arglist]]]
  end

  parse "unless not b then a end" do
    [:if,
     [:call, [:call, nil, :b, [:arglist]], :!, [:arglist]],
     [:nil],
     [:call, nil, :a, [:arglist]]]
  end

  parse "unless b then a end" do
    [:if, [:call, nil, :b, [:arglist]], [:nil], [:call, nil, :a, [:arglist]]]
  end
end
