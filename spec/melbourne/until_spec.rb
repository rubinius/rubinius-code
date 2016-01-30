describe "An Until node" do
  pre_until_sexp = [
    :until,
     [:call, nil, :a, [:arglist]],
     [:call, [:call, nil, :b, [:arglist]], :+, [:arglist, [:lit, 1]]],
     true
  ]

  parse <<-ruby do
      until a
        b + 1
      end
    ruby

    pre_until_sexp
  end

  parse "b + 1 until a" do
    pre_until_sexp
  end

  parse <<-ruby do
      begin
        b + 1
      end until a
    ruby

    [:until,
     [:call, nil, :a, [:arglist]],
     [:call, [:call, nil, :b, [:arglist]], :+, [:arglist, [:lit, 1]]],
     false]
  end

  nil_condition_sexp = [:until, [:nil], [:call, nil, :a, [:arglist]], true]

  parse "a until ()" do
    nil_condition_sexp
  end

  parse <<-ruby do
      until ()
        a
      end
    ruby

    nil_condition_sexp
  end
end
