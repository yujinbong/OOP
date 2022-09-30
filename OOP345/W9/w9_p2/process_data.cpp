// Workshop 9 - Multi-Threading, Thread Class
// process_data.cpp
// 2021/1/5 - Jeevan Pant
// Name      : Yujin Bong
// Student ID   : 147-525-208
// SECTIOMN     : NEE 
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops


#include "process_data.h"

namespace sdds_ws9 {

	void computeAvgFactor(const int* arr, int size, int divisor, double& avg) {
		avg = 0;
		for (int i = 0; i < size; i++) {   //0~125000....
			avg += arr[i];
		}
		avg /= divisor;// 125000/500000 헷갈려.,
	}

	void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var) {
		var = 0;
		for (int i = 0; i < size; i++) {
			var += (arr[i] - avg) * (arr[i] - avg);
		}
		var /= divisor;
	}
	ProcessData::operator bool() const {
		return total_items > 0 && data && num_threads > 0 && averages && variances && p_indices;
	}



	ProcessData::ProcessData(std::string filename, int n_threads) {
		// TODO: Open the file whose name was received as parameter and read the content
		//         into variables "total_items" and "data". Don't forget to allocate
		//         memory for "data".
		//       The file is binary and has the format described in the specs.
		std::ifstream istr(filename, std::ios::binary);
		int size;
		istr.read(reinterpret_cast<char*>(&size), sizeof(int)); //4byte!!
		int* tempData = new int[size];
		for (int i = 0; i < size; i++)
		{
			istr.read(reinterpret_cast<char*>(&tempData[i]), sizeof(int));
		}
		total_items = size;
		data = tempData;



		std::cout << "Item's count in file '" << filename << "': " << total_items << std::endl;
		std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
			<< data[total_items - 3] << ", " << data[total_items - 2] << ", "
			<< data[total_items - 1] << "]\n";

		// Following statements initialize the variables added for multi-threaded 
		//   computation
		num_threads = n_threads;
		averages = new double[num_threads] {}; //averages[0]
		variances = new double[num_threads] {};
		p_indices = new int[num_threads + 1]{};  //왜 +1???
		for (int i = 0; i < num_threads + 1; i++)
			p_indices[i] = i * (total_items / num_threads);

		/*
		0~124999
		125000 ~ 249999
		250000 ~ 374999
		375000 ~499999
		500000
		*/

	}
	ProcessData::~ProcessData() {
		delete[] data;
		delete[] averages;
		delete[] variances;
		delete[] p_indices;
	}

	// TODO Improve operator() function from part-1 for multi-threaded operation. Enhance the  
	//   function logic for the computation of average and variance by running the 
	//   function computeAvgFactor and computeVarFactor in multile threads. 
	// The function divides the data into a number of parts, where the number of parts is 
	//   equal to the number of threads. Use multi-threading to compute average-factor for 
	//   each part of the data by calling the function computeAvgFactor. Add the obtained 
	//   average-factors to compute total average. Use the resulting total average as the 
	//   average value argument for the function computeVarFactor, to compute variance-factors 
	//   for each part of the data. Use multi-threading to compute variance-factor for each 
	//   part of the data. Add computed variance-factors to obtain total variance.
	// Save the data into a file with filename held by the argument fname_target. 
	// Also, read the workshop instruction.

	int ProcessData::operator()(std::string filename, double& avg, double& var) //why prototype is int?
	{
		std::vector<std::thread> threads1;
		std::vector<std::thread> threads2;
		for (int i = 0; i < num_threads; i++)
		{
			auto f = std::bind(computeAvgFactor, data + p_indices[i], total_items / num_threads, total_items, std::ref(averages[i]));
			threads1.push_back(std::thread(f));
		}
		for (auto& thread : threads1) 
			thread.join();

		for (int i = 0; i < num_threads; i++)
		{
			avg += averages[i];
		}

		for (int i = 0; i < num_threads; i++)
		{
			auto f = std::bind(computeVarFactor, data + p_indices[i], total_items / num_threads, total_items, avg, std::ref(variances[i]));
			threads2.push_back(std::thread(f));
		}
		for (auto& thread : threads2)
			thread.join();

		for (int i = 0; i < num_threads; i++)
		{
			var += variances[i];
		}


		std::ofstream os(filename, std::ios::binary);
		os.write(reinterpret_cast<char*>(&total_items), sizeof(int));
		for (int i = 0; i < total_items; i++)
		{
			os.write(reinterpret_cast<char*>(&data[i]), sizeof(int));
		}
		return 0;
	}



}
