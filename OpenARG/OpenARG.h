#pragma once
#include <string>
#include <vector>

/// @brief GNU-Style Command Parser
class OpenARG
{
public:
	using item_t = struct
	{
		std::string Name;
		std::string Value;
	};
	using data_t = struct
	{
	};

public:
	OpenARG(int argc, char** argv);

	OpenARG(std::string const& args);

	~OpenARG();

	/// @brief Get item at index
	/// @param index 
	/// @return 
	item_t const& item(size_t index) const;

	/// @brief Get all items
	/// @return 
	std::vector<item_t> const& items() const;

	/// @brief Check swich existed
	/// @param name 
	/// @return 
	bool exist(std::string const& name) const;

	/// @brief Check swich existed & get index
	/// @param name 
	/// @param result 
	/// @return 
	bool index(std::string const& name, size_t& result) const;

	/// @brief Check swich existed & get indices
	/// @param name 
	/// @param result 
	/// @return 
	bool index(std::string const& name, std::vector<size_t>& result) const;

	/// @brief Get swich value if existed, otherwise return default value
	/// @param name 
	/// @param value default value
	/// @return 
	std::string value(std::string const& name, std::string const& value = std::string()) const;

	/// @brief Get swich values if existed, otherwise return default value
	/// @param name 
	/// @param value default value
	/// @return 
	std::vector<std::string> value(std::string const& name, std::vector<std::string> const& value = {}) const;

protected:
	data_t* m_Private;
};