#pragma once

// Make the class T non copyable
#define DECLARE_NONCOPYABLE(T)									\
		protected:												\
			T() {}												\
		public:													\
			~T() {}												\
		private:												\
			T(const T&) = delete;								\
			T& operator=(const T&) = delete;					\


// Make the class T Singleton
#define DECLARE_SINGLETON(T)									\
		DECLARE_NONCOPYABLE(T)									\
		public:													\
			static T* getInstance() {						\
				static T* instance(new T());				\
				return instance;								\
			}