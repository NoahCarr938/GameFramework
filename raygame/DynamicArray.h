#pragma once
//Tells c++ this is a templated class and we are going to pass in t
template<typename T>
class DynamicArray
{
public:
	// First constructor
	// Defining a default constructor
	DynamicArray();
	// Defining a default constructor that can be resized
	DynamicArray(const T* array, int size);
	// Constructor
	DynamicArray(const DynamicArray<T>& other);
	// Destructor
	~DynamicArray();

	// Copy assignment operator
	DynamicArray<T>& operator=(const DynamicArray<T>& other);
	T& operator[](int index);
	// Constant overload incase we want to get anything constant out of the array
	const T& operator[](int index) const;

	// So the array stores its length
	// Getter for the length
	int Length() const;
	// Function to resize array
	void Resize(int newSize);

	// Sets up dynamic array to be used with range based for loop
	// Needs to know where it begins and ends
	// Needs to be lowercase
	// Since we are making a list that will be looped over, we need these to show the beginning and end of arrays
	T* begin();
	const T* begin() const;
	T* end();
	const T* end() const;

	// Add a thing to the array
	// We are not going to change the value so it is const
	// Passes in a value
	void Add(const T& value);
	// Passes in an array
	void Add(const T* array, int size);
	// Passes in another Dynamic Array
	void Add(const DynamicArray<T>& other);
	// Add an item to the array but dont add it if already in the list
	void AddUnique(const T& value);
	// Insert into the middle of the array
	void Insert(int index, const T& value);
	// Insert an array in the middle
	void Insert(int index, const T* array, int size);
	// Insert a dynamic array in the middle
	void Insert(int index, const DynamicArray<T>& other);
	//Remove a specific thing from the list
	void RemoveIndex(int index);
	// Use const to show there will be no changes, it is just a container
	// Remove a value from the list
	void Remove(const T& value);
	// Remove an array
	void Remove(const T* array, int size);
	// Remove a dynamic array
	void Remove(const DynamicArray<T>& other);
	// No deleting except for our own array
	void Clear();

	void Contains(const T& value);

private:
	T* m_array;
	int m_length;

};

// When we define we are outside the class
template<typename T>
// Mark as inline because we are in the header
// Dynamic Array Default Constructor
inline DynamicArray<T>::DynamicArray()
{
	m_length = 0;
	m_array = new T[m_length];
}

template<typename T>
inline DynamicArray<T>::DynamicArray(const T* array, int size)
{

	m_length = size;
	m_array = new T[m_length];
	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = array[i];
	}
}

// Copy constructor
template<typename T>
inline DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
{
	m_length = other.m_length;
	m_array = new T[m_length];
	// Copy all the stuff in
	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = other.m_array[i];
	}
}
// The Destructor
template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
	delete[] m_array;
}

template<typename T>
inline DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other)
{
	m_length = other.m_length;
	// Delete array and then make a new one using the length
	delete[] m_array;
	m_array = new T[m_length];
	// Copying
	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = other.m_array[i];
	}
	return *this;
}

template<typename T>
inline T& DynamicArray<T>::operator[](int index)
{
	return m_array[index];
}

template<typename T>
inline const T& DynamicArray<T>::operator[](int index) const
{
	return m_array[index];
}

template<typename T>
inline int DynamicArray<T>::Length() const
{
	return m_length;
}

template<typename T>
inline void DynamicArray<T>::Resize(int newSize)
{
	// Making a new array of the size we are going to
	T* newArray = new T[newSize];
	// Makes certain we do not overflow either of the two arrays
	for (int i = 0; i < m_length && i < newSize; i++)
	{
		// Copy out the stuff from the old array into the new array
		newArray[i] = m_array[i];
	}
	delete[] m_array;
	m_array = newArray;
	m_length = newSize;
}

template<typename T>
inline T* DynamicArray<T>::begin()
{
	return m_array;
}

template<typename T>
inline const T* DynamicArray<T>::begin() const
{
	return m_array;
}

template<typename T>
inline T* DynamicArray<T>::end()
{
	return m_array + m_length;
}

template<typename T>
inline const T* DynamicArray<T>::end() const
{
	return m_array + m_length;
}

template<typename T>
inline void DynamicArray<T>::Add(const T& value)
{
	Resize(m_length + 1);
	m_array[m_length - 1] = value;
}

template<typename T>
inline void DynamicArray<T>::Add(const T* array, int size)
{
	int oldLength = m_length;
	Resize(m_length + size);
	for (int i = 0; i < size; i++)
	{
		m_array[oldLength + i] = array[i];
	}
}

template<typename T>
inline void DynamicArray<T>::Add(const DynamicArray<T>& other)
{
	int oldLength = m_length;
	Resize(m_length + other.m_length);
	for (int i = 0; i < other.Length; i++)
	{
		m_array[oldLength + i] = other.m_array[i];
	}
}

template<typename T>
inline void DynamicArray<T>::AddUnique(const T& value)
{
	for (int i = 0; i < m_length; i++)
	{
		if (m_array[i] == value)
			return;
	}
	Add(value);
}

template <typename T>
inline void DynamicArray<T>::Insert(int index, const T& value)
{
	Resize(m_length + 1);
	for (int i = m_length - 1; i > index; i--)
	{
		m_array[i] = m_array[i - 1];
	}
	m_array[index] = value;
}

template <typename T>
inline void DynamicArray<T>::Insert(int index, const T* array, int size)
{
	Resize(m_length + size);
	for (int i = m_length - 1; i >= index + size; i--)
	{
		m_array[i] = m_array[i - size];
	}
	for (int i = 0; i < size; i++)
	{
		m_array[index + i] = array[i];

	}
}

template <typename T>
inline void DynamicArray<T>::Insert(int index, const DynamicArray<T>& other)
{
	Resize(m_length + other.m_length);
	for (int i = m_length - 1; i >= index + other.m_length; i--)
	{
		m_array[i] = m_array[i - other.m_length];
	}
	for (int i = 0; i < other.m_length; i++)
	{
		m_array[index + i] = other.m_array[i];
	}
}

template <typename T>
inline void DynamicArray<T>::RemoveIndex(int index)
{
	for (int i = index; i < m_length - 1; i++)
	{
		m_array[i] = m_array[i + 1];
	}
	Resize(m_length - 1);
}

template <typename T>
inline void DynamicArray<T>::Remove(const T& value)
{
	for (int i = 0; i < m_length; i++)
	{
		if (m_array[i] == value)
		{
			RemoveIndex(i);
			return;
		}
	}
}

template <typename T>
inline void DynamicArray<T>::Remove(const T* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		Remove(array[i]);
	}
}

template <typename T>
inline void DynamicArray<T>::Remove(const DynamicArray<T>& other)
{
	for (int i = 0; i < other.m_length; i++)
	{
		Remove(other.m_array[i]);
	}
}

template <typename T>
inline void DynamicArray<T>::Clear()
{
	// Clear out all the references in the array, delete the array, reinitialize in an empty array
	Resize(0);
}

template<typename T>
inline void DynamicArray<T>::Contains(const T& value)
{
	for (int i = 0; i < length; i++)
	{

	}
}
