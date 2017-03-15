//
// Created by AJ Pryor on 3/2/17.
//

#ifndef PRISM_META_H
#define PRISM_META_H
#include <vector>
#include <string>
#include <cstddef>
#include "defines.h"
namespace PRISM{

	template <class T>
	class Metadata{
	public:
		Metadata(){
			interpolationFactor = 5;
			filename_atoms      = "/path/to/atoms.txt";
			filename_output     = "/path/to/output.mrc";
			realspace_pixelSize = 100.0 / 1000.0;
			potBound = 1.0;
			numFP = 8.0 / 8.0;
			sliceThickness = 2;
			cellDim = std::vector<size_t>{1,1,1}; // this is z,y,x format
			E0 = 80e3;
			alphaBeamMax = 24 / 1000.0;
			NUM_GPUS = 1;
			NUM_STREAMS_PER_GPU = 1;
			NUM_THREADS = 12;
			algorithm = Algorithm::PRISM; // 0 PRISM; 1 Multislice
			also_do_CPU_work = true;
		}
		size_t interpolationFactor; // PRISM f parameter
		std::string filename_atoms; // filename of txt file containing atoms (x,y,z,Z CSV format -- one atom per line)
		std::string filename_output;// filename of output image
		T realspace_pixelSize; // pixel size
		T cpu_gpu_ratio; // delete
		T potBound; // bounding integration radius for potential calculation
		size_t numFP; // number of frozen phonon configurations to compute
		T sliceThickness; // thickness of slice in Z
		bool also_do_CPU_work; // what fraction of computation to do on the cpu vs gpu
		std::vector<size_t> cellDim; // this is z,y,x format
		T E0; // electron energy
		T alphaBeamMax; // max semi angle for probe
		size_t NUM_THREADS; // number of CPU threads to use
		size_t NUM_GPUS; // number of GPUs to use
		size_t NUM_STREAMS_PER_GPU; // number of CUDA streams to use per GPU
		Algorithm algorithm;
	};
}
#endif //PRISM_META_H
