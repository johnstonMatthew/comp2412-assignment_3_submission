class Heap {
	private:
		int Size;
		int NumOfElements;

    public:
		int* Values;
		// Constructors
		Heap();
		Heap(int array[], int size);

		// Helpers
		void PrintValues();

		// Getters and Setters
		int GetSize();
		int GetNumOfElements();
		int* GetValues();
		void SetSize(int size);
		void SetNumOfElements(int numOfElements);
		void SetValues(int heap[]);

		// Parent and Child Index Getters
		int Parent(int index);
		int LeftChild(int index);
		int RightChild(int index);

		// Min Getters
		int GetMin();
		int ExtractMin();

		// Heap 'Validation'
		void FixMinNode(int index);
		void BuildHeap();

		// Sorting
		void HeapSort();

		//Operations
		void Insert(int value);
};

