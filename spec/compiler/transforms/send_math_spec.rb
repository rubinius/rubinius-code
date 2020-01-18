describe "A Call node using SendMath transform" do
  relates "a + b" do
    compile do |g|
      g.send_vcall :a
      g.unwind
      g.send_vcall :b
      g.unwind
      g.send :+, 1
      g.unwind
    end

    compile :math do |g|
      r0 = g.new_register
      r1 = g.new_register

      int = g.new_label
      done = g.new_label

      g.send_vcall :a
      g.unwind
      g.r_load_stack r0
      g.pop
      g.send_vcall :b
      g.unwind
      g.r_load_stack r1
      g.pop
      g.b_if_int r0, r1, int

      g.r_store_stack r0
      g.r_store_stack r1
      g.send :+ 1
      g.unwind
      g.goto done

      int.set!
      g.n_ile r0, r0, r1
      g.r_store_stack r0

      done.set!
    end
  end
end
