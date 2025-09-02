fun main() {
    var arr = arrayOf(1, 2, 3)  // Array with Initialization
    var a2: Array<Int> = Array(10) {0}  // Declare array without explicit Initialization
    println(arr[0])
    a2[0] = 5
    for (i in a2) {
        println(i)
    }

}