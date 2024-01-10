#include <iostream>

class STR {
	size_t m_size;
	size_t m_cap;
	char* m_ptr;
public:
	STR();
	void print();
	char& at(int);
	size_t size();
	size_t capacity();
	void reserve();
	void shrink_to_fit();
	bool empty();
	void clear();
	void push_back(char val);
	void pop_back();
	void insert(char val, int pos);
    char& front();
    char& back();
    const char* c_str();
    void erase(int pos, int count);
    void erase(int pos);
	STR substr(size_t& pos, size_t& count);
    size_t copy(char* s, size_t len, size_t pos);
    void resize(size_t n, char c);
    void swap(STR& s_ptr);
   // char* find();
   // void to_string();
   // void stoi();
	~STR();
};

STR::STR()
{
	m_size = 0;
	m_cap = 0;
	m_ptr = nullptr;
}
void STR::clear()
{
	if (m_ptr != nullptr) {
		delete[] m_ptr;
		m_ptr = nullptr;
		m_size = 0;
		m_cap = 0;
	}
}

size_t STR::size()
{
	return m_size;
}

size_t STR::capacity()
{
	return m_cap;
}

void STR::print()
{
	if (m_ptr != nullptr) {
	for (int i = 0; i < m_size; ++i) {
		std::cout << m_ptr[i];
		}
	}
}

char& STR::at(int pos)
{   
	if (pos < 0 || pos >= m_size) {
		std::cout << "no way";
	}
	return m_ptr[pos];
}

void STR::pop_back()
{
	if (m_size > 0) {
	--m_size;
	}
}

void STR::reserve()
{
	if (m_cap == 0) {
		m_cap = 8;
		m_ptr = new char[m_cap];
	}
	m_cap *= 2;
	char* tmp = new char[m_cap];
	for (int i = 0; i < m_size; ++i) {
		tmp[i] = m_ptr[i];
	}
	delete []m_ptr;
	m_ptr = tmp;
	tmp = nullptr;
}

void STR::push_back(char val)
{
	if (m_ptr == nullptr || m_size == m_cap) {
		reserve();
	}
	m_ptr[m_size] = val;
	++m_size;	
}

void STR::shrink_to_fit()
{
	if (m_size < m_cap) {
	char* tmp = new char[m_size];
	for (int i = 0; i < m_size; ++i) {
		tmp[i] = m_ptr[i];
		}
	m_cap = m_size;
	delete [] m_ptr;
	m_ptr = tmp;
	tmp = nullptr;
	}
}

bool STR::empty()
{
	if (m_ptr == nullptr) {
		return true;
	}
	return false;
}

void STR::insert(char val, int pos)
{
	if (pos < 0 || pos >= m_size) {
	std::cout << "no way";
	}
	if (m_size == m_cap) {
	reserve();
	}
	int index = m_size;
	m_size += 1;
	while (index != pos) {
		m_ptr[index] = m_ptr[index - 1];
		--index;
		}
	m_ptr[pos] = val;
}

char& STR::front()
{
    if (empty()) {
        std::cout << "no way";
    } 
        return m_ptr[0];
}

char& STR::back()
{
    if (empty()) {
    std::cout << "no way";
    }
    return m_ptr[size() - 1];
}

const char* STR::c_str()
{
    if (m_size == m_cap) {
        reserve();  
    }
    m_size += 1;
    char* tmp = new char[m_size];
    for (int i = 0; i < m_size - 1; ++i) {
        tmp[i] = m_ptr[i];
    }
    tmp[m_size - 1] = '\0';
    delete [] m_ptr;
    m_ptr = tmp;
    tmp = nullptr;
    return m_ptr;
}

void STR::erase(int pos, int count)
{
    if (pos < 0 || pos >= m_size || count > m_ptr[m_size - pos]) {
        std::cout << "no way";
    } else {
        for (int i = pos; i < m_size - count; ++i) {
            std::swap(m_ptr[i], m_ptr[i + count]);
            
        }
        m_size -= count;
    }
    
}
void STR::erase(int pos)
{
    if (pos < 0 || pos >= m_size) {
        std::cout << "no way";
        } else if (pos == m_size - 1) {
        --m_size;
        } else {
            for (int i = pos; i < m_size - 1; ++i) {
                std::swap(m_ptr[i], m_ptr[i + 1]);
            }
            --m_size;
        }
}

STR STR::substr(size_t& pos, size_t& count)
{
	STR obj; 
    if (pos >= m_size || pos + count >= m_size || empty()) {
        std::cout << "no way";
        return obj;
    }
    size_t size = pos + count;

    for (int i = pos; i < size; ++i) {
        obj.push_back(m_ptr[i]);
    }
    
    
    return obj;    
}

size_t STR::copy(char* s, size_t len, size_t pos)
{
    if (pos >= m_size || len >= m_size|| pos > len || empty()) {
        std::cout << "no way";
        return 0;
    }
    size_t count = 0;
    while (pos <= len) {
        s[count] = m_ptr[pos];
        ++pos;
        ++count;
    } 
    return count;
}

void STR::resize(size_t n, const char c)
{
    if (n < m_size) {
        m_size = n;
    } else if (n >= m_size && n < m_cap) {
       for (int i = m_size; i < n; ++i) {
            m_ptr[i] = c;
        }
            m_size = n;
    } else { 
        m_cap = n;
        char* tmp = new char [m_cap];
        for (int i = 0; i < m_size; ++i) {
            tmp[i] = m_ptr[i];
        }
        for (int i = m_size; i < m_cap; ++i) {
            tmp[i] = c;
        }
        delete m_ptr;
        m_ptr = tmp;
        tmp = nullptr;
    }

}


void STR::swap(STR& s_ptr)
{
     
        size_t tmp_size = m_size;
        m_size = s_ptr.m_size;
        s_ptr.m_size = tmp_size;
        size_t tmp_cap = m_cap;
        m_cap = s_ptr.m_cap;
        s_ptr.m_cap = tmp_cap;
        char* tmp = m_ptr;
        m_ptr = s_ptr.m_ptr;
        s_ptr.m_ptr = tmp;   
}

STR::~STR() 
{
	clear();
}

int main()
{
	STR A;
	A.push_back('c');
	A.push_back('d');
	A.push_back('e');
	A.push_back('f');
	A.push_back('g');
	A.print();	
    std::cout << std::endl;
	size_t pos = 1;
	size_t len = 3;
	STR B = A.substr(pos, len);
	B.print();


   /* STR B;
    B.push_back('a');
    B.push_back('z');
    B.push_back('y');
    B.print();
	std::cout << std::endl;
    A.swap(B);
    A.print();
    std::cout << std::endl;
    B.print();
//	A.insert('a', 2);
//	A.print();
//	std::cout << std::endl;
//	A.at(2) = 'M';
//	A.print();
//	A.pop_back();
//	A.print();
//	std::cout << std::endl;
//	std::cout << A.empty();
//	std::cout << A.capacity() << std::endl;
//	A.shrink_to_fit();
//	std::cout << A.capacity() << std::endl;
//	A.print();
    std::cout << std::endl;
   // std::cout << A.front() << std::endl;
   // std::cout << A.back() << std::endl;
   // std::cout << A.c_str() << std::endl;
   // A.erase(3);
   // A.print();
  //  std::cout << std::endl;
   // A.erase(3, 2);
   // A.print();
   // std::cout << std::endl;
   // std::cout << A.substr (0, 2) << std::endl;
   // A.print();
  //  char s[4]; 
    //std::cout << A.copy(s, 3, 1) << std::endl;
   // std::cout << s << std::endl;
   // A.resize(10, 's');
   // A.print();
   // std::cout << A.size();
    
    std::cout << str1.size() << " " << str1.capacity() << std::endl;
    std::cout << str2.size() << " " << str2.capacity() << std::endl;
    str1.swap(str2);
    std::cout << str1.size() << " " << str1.capacity() << std::endl;
    std::cout << str2.size() << " " << str2.capacity() << std::endl;*/
 
}
