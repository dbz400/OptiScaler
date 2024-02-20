#pragma once
#include "pch.h"

class Config
{
public:
	Config(std::wstring fileName);

	// Depth
	std::optional<bool> DepthInverted;

	// Color
	std::optional<bool> AutoExposure;
	std::optional<bool> HDR;

	// Motion
	std::optional<bool> JitterCancellation;
	std::optional<bool> DisplayResolution;

	//Logging
	std::optional<bool> LoggingEnabled;
	std::optional<bool> LogToFile;
	std::optional<bool> LogToConsole;
	std::optional<bool> OpenConsole;
	std::optional<int> LogLevel;
	std::optional<std::string> LogFileName;

	// XeSS
	std::optional<bool> DelayedInit;
	std::optional<bool> BuildPipelines;
	std::optional<int32_t> NetworkModel;

	// CAS
	std::optional<bool> CasEnabled;
	std::optional<int> ColorSpaceConversion;
	std::optional<bool> CasOverrideSharpness;
	std::optional<float> CasSharpness;


	// Upscale Ratio Override
	std::optional<bool> UpscaleRatioOverrideEnabled;
	std::optional<float> UpscaleRatioOverrideValue;
	
	// Quality Overrides
	std::optional<bool> QualityRatioOverrideEnabled;
	std::optional<float> QualityRatio_UltraQuality;
	std::optional<float> QualityRatio_Quality;
	std::optional<float> QualityRatio_Balanced;
	std::optional<float> QualityRatio_Performance;
	std::optional<float> QualityRatio_UltraPerformance;

	//Hotfixes
	std::optional<bool> DisableReactiveMask;
	std::optional<bool> ColorResourceBarrier;
	std::optional<bool> MVResourceBarrier;
	std::optional<bool> DepthResourceBarrier;
	std::optional<bool> ExposureResourceBarrier;
	std::optional<bool> MaskResourceBarrier;
	std::optional<bool> OutputResourceBarrier;

	void Reload();

private:
	CSimpleIniA ini;

	std::filesystem::path absoluteFileName;

	std::optional<std::string> readString(std::string section, std::string key, bool lowercase = false);
	std::optional<float> readFloat(std::string section, std::string key);
	std::optional<int> readInt(std::string section, std::string key);
	std::optional<bool> readBool(std::string section, std::string key);
};
