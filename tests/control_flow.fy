FancySpec describe: "Control Flow" with: {

  it: "should NOT call the block if not nil" for: 'if_nil: when: {
    'foo if_nil: { 'is_nil } . should == nil
    "hello, world" if_nil: { 'is_nil } . should == nil
  }

  it: "should work like if_true:" for: 'if:then: when: {
    if: (4 < 5) then: {
      4 < 5 should == true
    }
  }

  it: "should work like if_true:else: " for: 'if:then:else: when: {
    if: (4 < 5) then: {
      4 < 5 should == true
    } else: {
      4 < 5 should == nil
    }
  }

  it: "should work like while_true:" for: 'while:do: when: {
    x = 0
    while: { x < 10 } do: {
      x < 10 should == true
      x = x + 1
    }
    x == 10 should == true
  }

  it: "should work like while_false: " for: 'until:do: when: {
    x = 0
    until: { x == 10 } do: {
      x < 10 should == true
      x = x + 1
    }
    x == 10 should == true
  }

  it: "should work like if_false:: " for: 'unless:do: when: {
    unless: (4 > 5) do: {
      5 > 4 should == true
    }
  }

  it: "should only call the block if it's a true-ish value" for: 'if_do: when: {
    1 if_do: |num| {
      num * 10
    } . should == 10

    nil if_do: {
      "nope"
    } . should == nil

    false if_do: {
      "nope again"
    } . should == nil
  }

  it: "should call the then_block if it's a true-ish value and call the else_block otherwise" for: 'if_do:else: when: {
    1 if_do: |num| {
      num * 10
    } else: {
      nil
    } . should == 10

    nil if_do: {
      "nope"
    } else: {
      "yup"
    } . should == "yup"

    false if_do: {
      "nope again"
    } else: {
      "yup again"
    } . should == "yup again"
  }
}