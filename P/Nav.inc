<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Restaurant Management Dashboard</title>
  <link href="https://cdn.jsdelivr.net/npm/tailwindcss@2.2.19/dist/tailwind.min.css" rel="stylesheet">
  <script defer>
    function toggleMenu(id) {
      const el = document.getElementById(id);
      el.classList.toggle('hidden');
    }
  </script>
  <style>
    .bg-hero {
      background-image: url('https://images.unsplash.com/photo-1600891964599-f61ba0e24092?auto=format&fit=crop&w=1950&q=80');
      background-size: cover;
      background-position: center;
    }
  </style>
</head>
<body class="flex h-screen bg-gray-100">
  <!-- Sidebar -->
  <aside class="w-64 bg-white shadow-md p-4 space-y-4 overflow-y-auto">
    <h2 class="text-2xl font-bold text-gray-700">Restaurant Manager</h2>

    <nav class="space-y-2">
      <div>
        <button onclick="toggleMenu('menu1')" class="w-full flex justify-between items-center text-left p-2 hover:bg-gray-200 rounded">
          <span>Orders</span>
          <svg class="w-4 h-4" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M19 9l-7 7-7-7"></path></svg>
        </button>
        <div id="menu1" class="ml-4 mt-2 hidden space-y-1">
          <a href="login.php?op=1" class="block px-2 py-1 hover:bg-gray-100 rounded">New Orders</a>
          <a href="login.php?op=2" class="block px-2 py-1 hover:bg-gray-100 rounded">Order History</a>
        </div>
      </div>
      <div>
	<a href="login.php?op=3" class="block p-2 hover:bg-gray-200 rounded">Menu Management</a>
        <a href="login.php?op=4" class="block p-2 hover:bg-gray-200 rounded">Reservations</a>
        <a href="login.php?op=5" class="block p-2 hover:bg-gray-200 rounded">Staff Management</a>
        <a href="login.php?op=6" class="block p-2 hover:bg-gray-200 rounded">Reports</a>
      </div>
    </nav>
  </aside>

