int main() {
	int a[] = {5, 4, 3, 1, 7, 8, 9, 2, 1};
	insertionSort(a, sizeof(a)/sizeof(int));
	print(a, sizeof(a)/sizeof(int));
	
	double b[] = {5.5, 4.5, 1.2, 2.9, 9.2, 5.2};
	insertionSort(b, sizeof(b)/sizeof(double));
	print(b, sizeof(b)/sizeof(double));

	cout << sum(a, sizeof(a)/sizeof(int)) << '\n';
	cout << sum(b, sizeof(b)/sizeof(int)) << '\n';

	string c[] = {"yo", "ho", "test", "foo", "bar"};
	insertionSort(c, sizeof(c)/sizeof(string));
	print(c, sizeof(c)/sizeof(string));
}
