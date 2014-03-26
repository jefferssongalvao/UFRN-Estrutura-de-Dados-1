void preenche(int v[], int n){
    srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		v[i] = rand() % (n*n);
		if(v[i] == 0) v[i] = 1;
	}
}
void imprime(int v[], int n){
	for (int i = 0; i < n; ++i)
		cout << v[i] << " ";
	cout << "\n";
}
