#!/bin/bash
echo
echo "🚀 Compiling ..."
make || { echo "❌ Compilation failed"; exit 1; }
echo "✅ Compilation done"
echo

run_test() {
    test_name=$1
    input_content=$2
    old_word=$3
    new_word=$4
    expected=$5

    echo "🔹 $test_name"
    echo "📄 Input file :"
    echo "$input_content"
    echo "$input_content" > test.txt

    echo "⚙️ Executing : ./Sed_is_for_losers test.txt '$old_word' '$new_word'"
    ./Sed_is_for_losers test.txt "$old_word" "$new_word"

    result=$(cat test.txt.replace 2>/dev/null)
    
    echo "📤 Output file :"
    echo "$result"

    if [ "$result" = "$expected" ]; then
        echo "✅ Success"
    else
        echo "❌ Failure"
        echo "   🔹 Expected : $expected"
        echo "   🔸 Result  : $result"
    fi
    rm -f test.txt test.txt.replace
	echo
    echo "----------------------------------"
    echo
}

# ---------------- Test 1 : Basic input ----------------
run_test "Test 1 : Basic input" "Hello world, world!" "world" "universe" "Hello universe, universe!"

# ---------------- Test 2 : Basic input ----------------
run_test "Test 2 : Another basic input" "Batman is real, Batman is 4ever" "Batman" "Robin" "Robin is real, Robin is 4ever"

# ---------------- Test 3 : empty infile ----------------
run_test "Test 3 : empty infile" "" "Batman" "Robin" ""

# ---------------- Test 4 : new word empty ----------------
run_test "Test 4 : word to replace with is empty" "Batman is real, Batman is 4ever" "Batman" "" " is real,  is 4ever"

# ---------------- Test 5 : word to replace is empty ----------------
echo "🔹 Test 5 : word to replace is empty"
echo "Batman is real, Batman is 4ever" > test.txt
echo "⚙️ Executing : ./Sed_is_for_losers test.txt '' 'fail'"
./Sed_is_for_losers test.txt "" "fail" > output.log 2>&1
if grep -q "Error" output.log; then
    echo "✅ Success : error detected"
else
    echo "❌ Failure : error not detected"
fi
rm -f test.txt output.log
echo
echo "----------------------------------"
echo

# ---------------- Test 6 : No perms on infile ----------------
echo "🔹 Test 6 : No perms on infile"
echo "Batman" > test.txt
echo "Removing perms via chmod 000 on test.txt"
chmod 000 test.txt
echo "⚙️ Executing : ./Sed_is_for_losers test.txt 'test' 'fail'"
./Sed_is_for_losers test.txt "test" "fail" > output.log 2>&1
if grep -q "Error" output.log; then
    echo "✅ Success : error detected"
else
    echo "❌ Failure : error not detected"
fi
chmod 777 test.txt
rm -f test.txt output.log
echo
echo "----------------------------------"
echo



# ---------------- Test 7 : infile doesn't exist ----------------
echo "🔹 Test 6 : infile doesn't exist"
echo "⚙️ Executing : ./Sed_is_for_losers test.txt '' 'fail'"
./Sed_is_for_losers test.txt "" "fail" > output.log 2>&1
if grep -q "Error" output.log; then
    echo "✅ Success : error detected"
else
    echo "❌ Failure : error not detected"
fi
rm -f test.txt output.log
echo
echo "----------------------------------"
echo

echo "✅ All tests done !"

