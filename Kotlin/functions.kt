fun fib(a: Int): Int {
    if (a <= 0) return 0
    if (a <= 2) return 1
    return fib(a-1) + fib(a-2)
}

fun range(start: Int, stop: Int, func: (a: Int) -> Int) {
    for (i in start..stop) {
        println("fun($i) = ${func(i)}")
    }
}

fun main() {
    var foo = ::fib
    println("Function Testing...")
    range(1, 10, foo)
}