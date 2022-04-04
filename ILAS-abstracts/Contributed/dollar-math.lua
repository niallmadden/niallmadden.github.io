if not FORMAT:match('tex$') then return {} end

function Math (m)
  local delimiter = m.mathtype == 'InlineMath' and '$' or '$$'
  return pandoc.RawInline('tex', delimiter .. m.text .. delimiter)
end