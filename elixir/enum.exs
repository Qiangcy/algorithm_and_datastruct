defmodule Functions do
  def fun_all?([], _), do: false
  def fun_all?([head | tail], con) do 
    if(!con.(head)) do
      fun_all?(tail, con)
    else
      true
    end
  end

  def each([], _), do: []
  def each([head | tail], fun) do
    fun.(head)
    each(tail, fun)
  end

  def filter([], _), do: []
  def filter([head | tail], fun) do
    if fun.(head) do
      filter(tail, fun)
    else
      [head+1 | filter(tail, fun)]
    end
  end

  def map([], _), do: []
  def map([head | tail], fun), do: [ fun.(head) | map(tail, fun) ]

  def take([], _), do: []
  def take([head | tail], count) when count>0 do
    [head | take(tail, count-1)]
  end
  def take(_, _), do: []

  def flatten([]), do: []
  def flatten([head| tail]) when is_list(head) do
    flatten(head) 
    flatten(tail) 
  end
  def flatten([head| tail]) do
    [head | flatten(tail)]
  end


end

defmodule MyList do
  def flatten([]), do: []
  def flatten([ head | tail ]) do
    flatten(head) ++ flatten(tail)
  end
  def flatten(head), do: [head]
end

data = [1,2,3,4,5]

IO.puts Functions.fun_all?(data, &(&1 >= -1))

Functions.each(data, &(IO.puts &1))

IO.puts "filter %2: #{inspect Functions.filter(data, &(rem(&1, 2) == 0))}"
IO.puts "take 1: #{inspect Functions.take(data, 1)}"
IO.puts "take 10: #{inspect Functions.take(data, 10)}"
IO.puts "flatten: #{inspect Functions.flatten([1, [2, 3, [4]], 5])}"
# IO.puts "flatten: #{inspect Functions.flatten([ 1, [ 2, 3, [4] ], 5, [[[6]]]])}"
IO.puts "MyList:flatten: #{inspect MyList.flatten([1, [2, 3, [4]], 5])}"
