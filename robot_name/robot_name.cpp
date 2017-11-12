#include "robot_name.h"


namespace robot_name
{
	static robot_name::name_provisioner default_names_bucket;

	std::string robot_name::name_provisioner::provision_next()
	{
		if (provisioned_names.size() >= max_num_provisioned_names)
			throw NAME_PROVISIONER_OUT_OF_NAMES_EXCEPT;

		std::string candidate;
		bool was_elected = false;

		do
		{
			// Get new possible name
			candidate = gen_name();
			
			// Check if name is available
			auto elect_result = provisioned_names.insert(candidate);
			was_elected = elect_result.second;
		} while (!was_elected);

		return candidate;
	}

	std::string robot_name::name_provisioner::gen_name() const
	{
		static std::default_random_engine rand_e{ std::random_device{}() };
		static std::uniform_int_distribution<int> random_letter_d{ 'A', 'Z' };
		static std::uniform_int_distribution<int> random_digit_d{ '0', '9' };

		return {
			char(random_letter_d(rand_e)),
			char(random_letter_d(rand_e)),
			char(random_digit_d(rand_e)),
			char(random_digit_d(rand_e)),
			char(random_digit_d(rand_e))
		};
	}

	void robot_name::robot::reset()
	{
		_name = default_names_bucket.provision_next();
	}

	robot_name::robot::robot()
	{
		_name_provisioning_host = &default_names_bucket;

		reset();
	}

	std::string robot_name::robot::name() const
	{
		return _name;
	}
}
