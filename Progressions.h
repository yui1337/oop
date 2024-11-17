#include <vector>
#include <memory>
namespace Progress {
	class Progression {
	private:
		double _first;
	public:
		virtual double calculate_n_term(size_t n) const = 0;
		virtual double sum_of_first_n_terms(size_t n) const = 0;
		double get_first() const noexcept;
		virtual double get_step() const noexcept = 0;
		Progression() = default;
		Progression(const Progression&) = delete;
		Progression& operator=(const Progression&) = delete;
		Progression(double first);
		virtual ~Progression() = default;
	};
	class Arithmetic :public Progression {
	private:
		double _step;
	public:
		double get_step() const noexcept override;
		double calculate_n_term(size_t n) const override;
		double sum_of_first_n_terms(size_t n) const override;
		Arithmetic(double first, double step);
	};
	class Geometric :public Progression {
	private:
		double _denom;
	public:
		double get_step() const noexcept override;
		double calculate_n_term(size_t n) const override;
		double sum_of_first_n_terms(size_t n) const override;
		Geometric(double first, double denom);
	};
std::ostream& operator<<(std::ostream& os, const Progression& item) noexcept;
//std::ostream& operator<<(std::ostream& os, std::vector<std::shared_ptr<Progression>> massiv); 
Progression& max_sum_of_first_n(size_t n);
}