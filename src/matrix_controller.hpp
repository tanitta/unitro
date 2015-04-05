#pragma once
#include <data/matrix.hpp>
#include <data/cell.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <Eigen/Dense>
#undef Success
#include <limits>
namespace{
	// using namespace Eigen;
}
namespace unitro {
	class MatrixController {
		private:
			unitro::data::Matrix& matrix_ref_;
			bool IsWritable(Eigen::Vector3i& v, std::string param_key)const{}
			bool IsAddable(Eigen::Vector3i& v, std::string param_key)const{}
			bool IsRemovable(Eigen::Vector3i& v, std::string param_key)const{};
			unitro::data::Cell& GetCellRef(const Eigen::Vector3i& v)const{
				return matrix_ref_[v[0]][v[1]][v[2]];
			}

		public:
			MatrixController(unitro::data::Matrix& matrix_ref):matrix_ref_(matrix_ref){};
			virtual ~MatrixController(){};
			void Add(const Eigen::Vector3i& v, const std::string& param_key, const double amount){
				GetCellRef(v)[param_key] += amount;
			}

			void Remove(const Eigen::Vector3i& v, const std::string& param_key, const double amount){
				GetCellRef(v)[param_key] -= amount;
			}

			void MoveForce(const Eigen::Vector3i& v1, const Eigen::Vector3i& v2, const std::string& param_key, const double& amount){
				GetCellRef(v1)[param_key] -= amount;
				GetCellRef(v2)[param_key] += amount;
			}

			void Move(const Eigen::Vector3i& v1, const Eigen::Vector3i& v2, const std::string& param_key, const double& amount, const double& min = 0.0, const double& max = std::numeric_limits<double>::max()){
				if(GetCellRef(v1)[param_key]-amount >= min && GetCellRef(v2)[param_key]+amount <= max){
					MoveForce(v1,v2,param_key,amount);
				}
			}

			void DiffuseNeumann(const Eigen::Vector3i& v, const std::string& param_key, const double& amount){
				double each_amount = amount/6;
				Move(v,Eigen::Vector3i(v[0]-1,v[1],v[2]),param_key,each_amount);
				Move(v,Eigen::Vector3i(v[0]+1,v[1],v[2]),param_key,each_amount);
				Move(v,Eigen::Vector3i(v[0],v[1]-1,v[2]),param_key,each_amount);
				Move(v,Eigen::Vector3i(v[0],v[1]+1,v[2]),param_key,each_amount);
				Move(v,Eigen::Vector3i(v[0],v[1],v[2]-1),param_key,each_amount);
				Move(v,Eigen::Vector3i(v[0],v[1],v[2]+1),param_key,each_amount);
			}

			void DiffuseMoore(const Eigen::Vector3i& v, const std::string& param_key, const double& amount){}

	};
} // namespace unitro
