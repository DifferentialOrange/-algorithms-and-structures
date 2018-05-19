#include <vector>
#include <string>
#include <cstdio>

const static unsigned BASE = 1e9;

struct n_num
{
	bool empty;
	std::vector<unsigned> data;

	n_num() 
	{
		empty = true;
		data.clear();
	}

	n_num(unsigned num)
	{
		empty = false;
		data.push_back(num);
	}

	n_num(std::string& num)
	{
		empty = false;
		size_t i;
		for (i = 0; i < num.size() / 9; i++)
			data.push_back((unsigned)stoul(num.substr(num.size() - i * 9 - 9, 9)));
		if (i * 9 < num.size())
			data.push_back((unsigned)stoul(num.substr(0, num.size() - i * 9)));
	}

	bool isEmpty()
	{
		return empty;
	}

	void output()
	{
		auto iter = data.rbegin();
		printf("%u", *iter);
		for (iter++; iter != data.rend(); iter++)
			printf("%09u", *iter);
		printf("\n");
	}

	n_num operator+(const n_num& b) const
	{
		size_t i;
		unsigned  carry = 0;
		n_num ans;

		for (i = 0; i < std::min(data.size(), b.data.size()); i++)
		{		
			ans.data.push_back((data[i] + b.data[i] + carry) % BASE);
			carry = (data[i] + b.data[i] + carry) / BASE;
		}


		for (; i < data.size(); i++)
		{		
			ans.data.push_back((data[i] + carry) % BASE);
			carry = (data[i] + carry) / BASE;
		}
		
		for (; i < b.data.size(); i++)
		{
			ans.data.push_back((b.data[i] + carry) % BASE);
			carry = (b.data[i] + carry) / BASE;
		}

		if (carry)
			ans.data.push_back(carry);

		return ans;
	}

	n_num& operator+=(const n_num& b)
	{
		size_t i;
		unsigned carry = 0, tmp;

		for (i = 0; i < std::min(data.size(), b.data.size()); i++)
		{			
			tmp = (data[i] + b.data[i] + carry) % BASE;
			carry = (data[i] + b.data[i] + carry) / BASE;
			data[i] = tmp;
		}

		for (; i < data.size(); i++)
		{
			tmp = (data[i] + carry) % BASE;
			carry = (data[i] + carry) / BASE;
			data[i] = tmp;
		}

		for (; i < b.data.size(); i++)
		{
			data.push_back((b.data[i] + carry) % BASE);
			carry = (b.data[i] + carry) / BASE;
		}

		if (carry)
			data.push_back(carry);

		return *this;
	} 


	n_num operator*(const n_num& b) const
	{
		n_num ans(0);

		for (size_t j = 0; j < b.data.size(); j++)
		{
			n_num term;
			unsigned carry = 0;

			for (size_t zeros = 0; zeros < j; zeros++)
				term.data.push_back(0);

			for (size_t i = 0; i < data.size(); i++)
			{
				term.data.push_back(((unsigned long long)data[i] * (unsigned long long)b.data[j] + carry) % BASE);
				carry = ((unsigned long long)data[i] * (unsigned long long)b.data[j] + carry) / BASE;
			}

			if (carry)
				term.data.push_back(carry);

			ans += term;
		}

		return ans;
	}

	n_num& half()
	{
		unsigned carryFlag = 0, tmp;

		auto iter = data.rbegin();
		if (*iter / 2)
		{
			tmp = *iter / 2;
			carryFlag = *iter % 2;
			*iter = tmp;
		}
		else
		{
			carryFlag = *iter % 2;
			data.erase(--data.end());
		}

		for (iter++; iter != data.rend(); iter++)
		{
			tmp = (*iter + carryFlag * BASE) / 2;
			carryFlag = (*iter + carryFlag * BASE) % 2;
			*iter = tmp;
		}

		return (*this);
	}

	bool operator<(const n_num& b) const
	{
		if (data.size() < b.data.size())
			return true;
		if (data.size() > b.data.size())
			return false;

		for (size_t i = 0; i < data.size(); i++)
		{
			if (data[data.size() - i - 1] > b.data[b.data.size() - i - 1])
				return false;
			else if (data[data.size() - i - 1] < b.data[b.data.size() - i - 1])
				return true;
		}

		return false;
	}

	bool operator>(const n_num& b) const
	{
		return b < *this;
	}

	bool operator==(const n_num& b) const
	{
		if (data.size() != b.data.size())
			return false;

		for (size_t i = 0; i < data.size(); i++)
			if (data[data.size() - i] != b.data[data.size() - i])
				return false;

		return true;
	}

	n_num &operator++(int)
	{
		unsigned carry = (data[0] + 1) / BASE;
		data[0] = (data[0] + 1) % BASE;

		for (size_t i = 1; carry && i < data.size(); i++)
		{
			carry = (data[i] + 1) / BASE;
			data[i] = (data[i] + 1) % BASE;
		}

		if (carry)
			data.push_back(carry);

		return (*this);
	}
};